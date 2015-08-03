#ifndef TOPJCDIALOG_H
#define TOPJCDIALOG_H

#include <retroshare-gui/mainpage.h>
#include <retroshare/rsfiles.h>
#include <retroshare/rspeers.h>


#include <QWidget>

namespace Ui {
class TopJCDialog;
}

class TopJCDialog  : public MainPage
{
    Q_OBJECT
    
public:
    explicit TopJCDialog(QWidget *parent = 0);
    ~TopJCDialog();
    
public slots:
    void NeMsgArrived(const RsPeerId &peer_id, QString str);
private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::TopJCDialog *ui;
};

#endif // TOPJCDIALOG_H
