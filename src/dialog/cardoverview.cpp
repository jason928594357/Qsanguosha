#include "cardoverview.h"
#include "ui_cardoverview.h"
#include "engine.h"

static CardOverview *Overview;

CardOverview *CardOverview::getInstance(QWidget *main_window)
{
    if (Overview == NULL){
        Overview = new CardOverview(main_window);
    }
    return Overview;
}

CardOverview::CardOverview(QWidget *parent)
    : QDialog(parent), ui(new Ui::CardOverview){
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0, 80);
    ui->tableWidget->setColumnWidth(1, 60);
    ui->tableWidget->setColumnWidth(2, 30);
    ui->tableWidget->setColumnWidth(3, 60);
    ui->tableWidget->setColumnWidth(4, 70);
}

void CardOverview::loadFromAll(){
    //int n = Sanguosha->getCardCount();
}

CardOverview::~CardOverview()
{
    delete ui;
}
