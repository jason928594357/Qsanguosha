#ifndef FLATDIALOG_H
#define FLATDIALOG_H

#include <QDialog>

class FlatDialog : public QDialog {
    Q_OBJECT

public:
    FlatDialog(QWidget *parent = 0, bool initialLayoutWithTitle = true);
};

#endif // FLATDIALOG_H
