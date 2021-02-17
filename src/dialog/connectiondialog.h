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

private:
    Ui::ConnectionDialog *ui;
};

#endif // CONNECTIONDIALOG_H
