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
    ui->tableWidget->setColumnWidth(1, 70);
    ui->tableWidget->setColumnWidth(2, 35);
    ui->tableWidget->setColumnWidth(3, 60);
    ui->tableWidget->setColumnWidth(4, 80);
}

void CardOverview::loadFromAll(){
    int n = Sanguosha->getCardCount();
    ui->tableWidget->setRowCount(n);
    for(int i = 0; i < n; i++){
       const Card *card = Sanguosha->getEngineCard(i);
       addCard(i,card);
    }
    if(n > 0){
        // 当前行高亮
        ui->tableWidget->setCurrentItem(ui->tableWidget->item(0 , 0));

        const Card *card = Sanguosha->getEngineCard(0);
        if(card->getTypeId() == Card::TypeBasic){
            ui->playAudioEffectButton->show();
            ui->malePlayButton->hide();
            ui->femalePlayButton->hide();
        }else {
            ui->playAudioEffectButton->hide();
            ui->malePlayButton->show();
            ui->femalePlayButton->show();
        }
    }
}

CardOverview::~CardOverview()
{
    delete ui;
}

void CardOverview::addCard(int i, const Card *card){
    QString name = Sanguosha->translate(card->objectName());
    QIcon suit_icon = QIcon(QString("image/system/suit/%1.png").arg(card->getSuitString()));
    QString suit_str = Sanguosha->translate(card->getSuitString());
    QString point = card->getNumberString();
    QString type = Sanguosha->translate(card->getType());
    QString subtype = Sanguosha->translate(card->getSubtype());
    QString package = Sanguosha->translate(card->getPackage());

    QTableWidgetItem *name_item = new QTableWidgetItem(name);
    QTableWidgetItem *package_item = new QTableWidgetItem(package);

    name_item->setData(Qt::UserRole,card->getId());
    ui->tableWidget->setItem(i, 0, name_item);
    ui->tableWidget->setItem(i, 1, new QTableWidgetItem(suit_icon, suit_str));
    ui->tableWidget->setItem(i, 2, new QTableWidgetItem(point));
    ui->tableWidget->setItem(i, 3, new QTableWidgetItem(type));
    ui->tableWidget->setItem(i, 4, new QTableWidgetItem(subtype));
    ui->tableWidget->setItem(i, 5, package_item);
}
