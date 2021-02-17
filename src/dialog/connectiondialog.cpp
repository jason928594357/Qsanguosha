#include "connectiondialog.h"
#include "ui_connectiondialog.h"


ConnectionDialog::ConnectionDialog(QWidget *parent) :
    FlatDialog(parent,false),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}


