This is a test plugin that lets you chat with minimal code!

###include easy transport

    #include "interface/rsEasyTransport.h"


###connect

    connect(rsEasyTransport->mNotify, SIGNAL(NeMsgArrived(RsPeerId,QString)), this , SLOT(NeMsgArrived(RsPeerId,QString)));

###send message

    rsEasyTransport->msg_all(ui->lineEdit->text().toStdString());
