#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include "flatdialog.h"

class ServerDialog : public FlatDialog {
    Q_OBJECT
public:
    ServerDialog(QWidget *parent);
    bool config();
};

#endif // SERVERDIALOG_H
