#include "generaloverview.h"
#include "ui_generaloverview.h"

GeneralOverview::GeneralOverview(QWidget *parent)
    : FlatDialog(parent, false), ui(new Ui::GeneralOverview), all_generals(NULL)
{
    ui->setupUi(this);
}

GeneralOverview::~GeneralOverview()
{
    delete ui;
}
