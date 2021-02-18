#include "cardoverview.h"
#include "ui_cardoverview.h"

CardOverview::CardOverview(QWidget *parent) :
     FlatDialog(parent, false), ui(new Ui::CardOverview)
{
    ui->setupUi(this);
}

CardOverview::~CardOverview()
{
    delete ui;
}
