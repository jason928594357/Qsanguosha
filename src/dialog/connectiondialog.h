#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include "flatdialog.h"

namespace Ui {
    class ConnectionDialog;
}
class ConnectionDialog :public FlatDialog{
    Q_OBJECT

public:
    ConnectionDialog(QWidget *parent);
    ~ConnectionDialog();
    void hideAvatarList();
    void showAvatarList();

private:
    Ui::ConnectionDialog *ui;

private slots:

};

#endif // CONNECTIONDIALOG_H
