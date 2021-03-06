#include "generaloverview.h"
#include "ui_generaloverview.h"

static GeneralOverview *Overview;

GeneralOverview::GeneralOverview(QWidget *parent)
    :QDialog(parent), ui(new Ui::GeneralOverview)
{
    ui->setupUi(this);
}

GeneralOverview::~GeneralOverview(){
    delete ui;
}

GeneralOverview *GeneralOverview::getInstance(QWidget *main_window){
    if(Overview == NULL){
        Overview = new GeneralOverview(main_window);
    }
    return Overview;
}
