#include <retroshare/rsplugin.h>
#include <util/rsversioninfo.h>
#include <QTranslator>
#include <QIcon>

#include "ETChatPlugin.h"
//#include "LinksDialog.h"
#include "topjcdialog.h"

//static void *inited = new ETChatPlugin();

//inited->rs_cache_service();

extern "C" {
	void *RETROSHARE_PLUGIN_provide()
	{
        static ETChatPlugin *p = new ETChatPlugin() ;

		return (void*)p ;
	}

	// This symbol contains the svn revision number grabbed from the executable. 
	// It will be tested by RS to load the plugin automatically, since it is safe to load plugins
	// with same revision numbers, assuming that the revision numbers are up-to-date.
	//
	uint32_t RETROSHARE_PLUGIN_revision = RS_REVISION_NUMBER ;

	// This symbol contains the svn revision number grabbed from the executable. 
	// It will be tested by RS to load the plugin automatically, since it is safe to load plugins
	// with same revision numbers, assuming that the revision numbers are up-to-date.
	//
	uint32_t RETROSHARE_PLUGIN_api = RS_PLUGIN_API_VERSION ;
}

#define IMAGE_LINKS ":/images/dice.png"

void ETChatPlugin::getPluginVersion(int& major, int& minor, int &build, int& svn_rev) const
{
	major = RS_MAJOR_VERSION;
	minor = RS_MINOR_VERSION;
	build = RS_BUILD_NUMBER;
	svn_rev = RS_REVISION_NUMBER;
}

ETChatPlugin::ETChatPlugin()
{
    //mRanking = NULL ;
	mainpage = NULL ;
        mIcon = NULL ;
        mPlugInHandler = NULL;
        mPeers = NULL;
        mFiles = NULL;
}

void ETChatPlugin::setInterfaces(RsPlugInInterfaces &interfaces){

    mPeers = interfaces.mPeers;
    mFiles = interfaces.mFiles;
}

MainPage *ETChatPlugin::qt_page() const
{
	if(mainpage == NULL)
                mainpage = new TopJCDialog();//mPeers, mFiles) ;

	return mainpage ;
}

RsCacheService *ETChatPlugin::rs_cache_service() const
{
    /*if(mRanking == NULL)
	{
                mRanking = new p3Ranking(mPlugInHandler) ; // , 3600 * 24 * 30 * 6); // 6 Months
		rsRanks = mRanking ;
	}

    return mRanking ;*/
    return NULL;
}

void ETChatPlugin::setPlugInHandler(RsPluginHandler *pgHandler){
    mPlugInHandler = pgHandler;

}

QIcon *ETChatPlugin::qt_icon() const
{
	if(mIcon == NULL)
	{
        Q_INIT_RESOURCE(ETChat_images) ;

        mIcon = new QIcon(IMAGE_LINKS) ;
	}

	return mIcon ;
}

std::string ETChatPlugin::getShortPluginDescription() const
{
    return "infosoon";//QApplication::translate("ETChatPlugin", "This plugin provides a set of cached links, and a voting system to promote them.").toUtf8().constData();
}

std::string ETChatPlugin::getPluginName() const
{
    return "ETChat";//QApplication::translate("ETChatPlugin", "ETChat").toUtf8().constData();
}

QTranslator* ETChatPlugin::qt_translator(QApplication */*app*/, const QString& languageCode, const QString& externalDir) const
{
	if (languageCode == "en") {
		return NULL;
	}

	QTranslator* translator = new QTranslator();

    if (translator->load(externalDir + "/ETChat_" + languageCode + ".qm")) {
		return translator;
    } else if (translator->load(":/lang/ETChat_" + languageCode + ".qm")) {
		return translator;
	}

	delete(translator);
	return NULL;
}
