#include "topjcdialog.h"
#include "ui_topjcdialog.h"

#include "interface/rsEasyTransport.h"

/** Constructor
LinksDialog::LinksDialog(RsPeers *peers, RsFiles *files, QWidget *parent)
: MainPage(parent), mPeers(peers), mFiles(files)
{

}**/

class rsEasyTransport;

TopJCDialog::TopJCDialog(QWidget *parent) :
    MainPage(parent),
    ui(new Ui::TopJCDialog)
{
    ui->setupUi(this);
    connect(rsEasyTransport->mNotify, SIGNAL(NeMsgArrived(RsPeerId,QString)), this , SLOT(NeMsgArrived(RsPeerId,QString)));
}

TopJCDialog::~TopJCDialog()
{
    delete ui;
}

void TopJCDialog::on_lineEdit_returnPressed()
{
    rsEasyTransport->msg_all(ui->lineEdit->text().toStdString());
}


void TopJCDialog::NeMsgArrived(const RsPeerId &peer_id, QString str)
{

	std::cout << "GUI got Packet from: " << peer_id;
	std::cout << " saying " << str.toStdString();
	std::cout << std::endl;

	QString output = QString::fromStdString(rsPeers->getPeerName(peer_id));
	output+=": ";
	output+=str;
	ui->textBrowser->append(output);
}
