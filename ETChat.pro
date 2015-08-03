!include("../Common/retroshare_plugin.pri"): error("Could not include file ../Common/retroshare_plugin.pri")


INCLUDEPATH += ../EasyTransport/
#LIBS += /home/chozabu/.retroshare/extensions6/libEasyTransport.so
#LIBS += /home/chozabu/.retroshare/extensions6/libEasyTransport.so.1

CONFIG += qt uic qrc resources

greaterThan(QT_MAJOR_VERSION, 4) {
	# Qt 5
	QT     += widgets
} 

SOURCES = ETChatPlugin.cpp \
    topjcdialog.cpp
HEADERS = ETChatPlugin.h \
    topjcdialog.h
FORMS   = \
    topjcdialog.ui

TARGET = ETChat

RESOURCES = ETChat_images.qrc

TRANSLATIONS +=  \
			lang/ETChat_cs.ts \
			lang/ETChat_da.ts \
			lang/ETChat_de.ts \
			lang/ETChat_el.ts \
			lang/ETChat_en.ts \
			lang/ETChat_es.ts \
			lang/ETChat_fi.ts \
			lang/ETChat_fr.ts \
			lang/ETChat_hu.ts \
			lang/ETChat_it.ts \
			lang/ETChat_ja_JP.ts \
			lang/ETChat_ko.ts \
			lang/ETChat_nl.ts \
			lang/ETChat_pl.ts \
			lang/ETChat_ru.ts \
			lang/ETChat_sv.ts \
			lang/ETChat_tr.ts \
			lang/ETChat_zh_CN.ts

OTHER_FILES += \
    testit.sh
