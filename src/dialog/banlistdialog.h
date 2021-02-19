#ifndef BANLISTDIALOG_H
#define BANLISTDIALOG_H

#include "flatdialog.h"

class BanListDialog : public FlatDialog {
    Q_OBJECT
public:
    BanListDialog(QWidget *parent, bool view = false);
};

#endif // BANLISTDIALOG_H
