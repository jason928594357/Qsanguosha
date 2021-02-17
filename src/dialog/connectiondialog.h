#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QWidget>

#include "flatdialog.h"

namespace Ui {
    class ConnectionDialog;
}

class ConnectionDialog : public FlatDialog
{
    Q_OBJECT

public:
    ConnectionDialog(QWidget *parent);
    ~ConnectionDialog();
    void hideAvatarList();
    void showAvatarList();
private:
    Ui::ConnectionDialog *ui;

private slots:
    void on_detectLANButton_clicked();
    void on_clearHistoryButton_clicked();
    void on_avatarList_doubleClicked(const QModelIndex &index);
    void on_changeAvatarButton_clicked();
    void on_connectButton_clicked();
};

#endif // CONNECTIONDIALOG_H
