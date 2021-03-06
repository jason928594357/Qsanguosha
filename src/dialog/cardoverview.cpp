#include "cardoverview.h"
#include "ui_cardoverview.h"
#include "engine.h"
#include "skinbank.h"

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
    ui->tableWidget->setColumnWidth(1, 75);
    ui->tableWidget->setColumnWidth(2, 35);
    ui->tableWidget->setColumnWidth(3, 70);
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
        if(card->getTypeId() == Card::TypeEquip || card->getName() == "peach"){
            ui->playAudioEffectButton->show();
            ui->malePlayButton->hide();
            ui->femalePlayButton->hide();
        } else {
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
    QString name = Sanguosha->translate(card->getCardName());
    QIcon suit_icon = QIcon(QString("image/system/suit/%1.png").arg(card->getSuitString()));
    QString suit_str = Sanguosha->translate(card->getSuitStringTr());
    QString point = card->getNumberString();
    QString type = Sanguosha->translate(card->getType());
    QString subtype = Sanguosha->translate(card->getSubtype());
    QString package = Sanguosha->translate(card->getPackageName());

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

void CardOverview::on_tableWidget_itemDoubleClicked(QTableWidgetItem *){

}

void CardOverview::on_tableWidget_itemSelectionChanged(){
    int row = ui->tableWidget->currentRow();
    int card_id = ui->tableWidget->item(row,0)->data(Qt::UserRole).toInt();
    const Card *card = Sanguosha->getEngineCard(card_id);
    QString pixmap_path = QString("image/big-card/%1.png").arg(card->objectName());
    ui->cardLabel->setPixmap(pixmap_path);
    ui->cardDescriptionBox->setText(card->getDescription());
    if (card->getTypeId() == Card::TypeEquip || card->getName() == "peach") {
        ui->playAudioEffectButton->show();
        ui->malePlayButton->hide();
        ui->femalePlayButton->hide();
    } else {
        ui->playAudioEffectButton->hide();
        ui->malePlayButton->show();
        ui->femalePlayButton->show();
    }
}

void CardOverview::on_malePlayButton_clicked(){
    int row = ui->tableWidget->currentRow();
    if(row >= 0){
        int card_id = ui->tableWidget->item(row, 0)->data(Qt::UserRole).toInt();
        const Card *card = Sanguosha->getEngineCard(card_id);
        Sanguosha->playAudioEffect(G_ROOM_SKIN.getPlayerAudioEffectPath(card->objectName(),true),false);
    }
}

void CardOverview::on_femalePlayButton_clicked(){
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        int card_id = ui->tableWidget->item(row, 0)->data(Qt::UserRole).toInt();
        const Card *card = Sanguosha->getEngineCard(card_id);
        Sanguosha->playAudioEffect(G_ROOM_SKIN.getPlayerAudioEffectPath(card->objectName(), false), false);
    }
}

void CardOverview::on_playAudioEffectButton_clicked(){
    int row = ui->tableWidget->currentRow();
    if(row >= 0){
        int card_id = ui->tableWidget->item(row,0)->data(Qt::UserRole).toInt();
        const Card *card = Sanguosha->getEngineCard(card_id);
        if(card->getName() == "peach"){
            QString fileName = G_ROOM_SKIN.getPlayerAudioEffectPath(QString("peach"),QString("default"),-1);
            Sanguosha->playAudioEffect(fileName,false);
        }
        if(card->getTypeId() == Card::TypeEquip){
            QString objectName = card->objectName();
            QString fileName = G_ROOM_SKIN.getPlayerAudioEffectPath(objectName, QString("equip"), -1);
            Sanguosha->playAudioEffect(fileName,false);
        }
    }
}
