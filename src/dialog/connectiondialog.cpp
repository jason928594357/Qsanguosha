#include "connectiondialog.h"
#include "ui_connectiondialog.h"
#include "settings.h"

#include <QMessageBox>
#include <QScrollBar>

static const int ShrinkWidth = 317;
static const int ExpandWidth = 619;

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    FlatDialog(parent,false),
    ui(new Ui::ConnectionDialog)
{

    ui->setupUi(this);
    connect(this, &ConnectionDialog::windowTitleChanged, ui->title, &QLabel::setText);
    QScrollBar *bar = ui->avatarList->verticalScrollBar();
    //bar->setStyleSheet(StyleHelper::styleSheetOfScrollBar());
    resize(ShrinkWidth, height());
    ui->connectButton->setFocus();
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::hideAvatarList() {
    if (!ui->avatarList->isVisible()) return;
    ui->avatarList->hide();
}

void ConnectionDialog::showAvatarList(){
    if(ui->avatarList->isVisible()){
        return;
    }

    if(ui->avatarList->model() == NULL){
//        QList<const General *> generals = Sanguosha->getGeneralList();
    }
    ui->avatarList->show();
}

void ConnectionDialog::on_connectButton_clicked(){
    QString username = ui->nameLineEdit->text();
    if(username.isEmpty()){
        QMessageBox::warning(this, tr("Warning"), tr("The user name can not be empty!"));
        return;
    }
    Config.UserName = username;
    Config.HostAddress = ui->hostComboBox->lineEdit()->text();
    Config.RoomPassword = ui->passwordEdit->text();

    Config.setValue("UserName", Config.UserName);
    Config.setValue("HostAddress", Config.HostAddress);
    Config.setValue("EnableReconnection", ui->reconnectionCheckBox->isChecked());

    accept();
}

void ConnectionDialog::on_changeAvatarButton_clicked(){
    if(ui->avatarList->isVisible()){
        QModelIndex index = ui->avatarList->currentIndex();
        if(index.isValid()){
            on_avatarList_doubleClicked(index);
        } else {
            hideAvatarList();
            resize(ShrinkWidth,height());
        }
    } else {
        showAvatarList();
        resize(ExpandWidth, height());
    }
}

void ConnectionDialog::on_avatarList_doubleClicked(const QModelIndex &index){

}

void ConnectionDialog::on_clearHistoryButton_clicked() {
    ui->hostComboBox->clear();
    ui->hostComboBox->lineEdit()->clear();

    //Config.HistoryIPs.clear();
    //Config.remove("HistoryIPs");
}

void ConnectionDialog::on_detectLANButton_clicked() {

}
