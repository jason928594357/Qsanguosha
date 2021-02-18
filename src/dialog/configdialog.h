#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include "flatdialog.h"

class QLineEdit;

namespace Ui {
    class ConfigDialog;
}

class ConfigDialog : public FlatDialog {
    Q_OBJECT

public:
    ConfigDialog(QWidget *parent = 0);
    ~ConfigDialog();

private:
    Ui::ConfigDialog *ui;
};

#endif // CONFIGDIALOG_H
