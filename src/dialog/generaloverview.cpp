#include "generaloverview.h"
#include "ui_generaloverview.h"
#include "engine.h"

#include <QGroupBox>

static GeneralOverview *Overview;

GeneralOverview::GeneralOverview(QWidget *parent)
    :QDialog(parent), ui(new Ui::GeneralOverview)
{
    ui->setupUi(this);
    origin_window_title = windowTitle();
    button_layout = new QVBoxLayout;
    QGroupBox *group_box = new QGroupBox;
    group_box->setTitle(tr("Effects"));
    group_box->setLayout(button_layout);
    ui->scrollArea->setWidget(group_box);
    ui->returnButton->hide();
}

GeneralOverview::~GeneralOverview(){
    delete ui;
}

void GeneralOverview::fillGenrals(const QList<const General *> &generals, bool init){
    QList<const General *> copy_generals;
    foreach(const General *general, generals){
        copy_generals.append(general);
    }
    if(init){
        ui->returnButton->hide();
        setWindowTitle(origin_window_title);
        all_generals = copy_generals;
    }
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(copy_generals.length());
    ui->tableWidget->setIconSize(QSize(20, 20));
    // 主公logo
    QIcon lord_icon("image/system/roles/lord.png");
    for (int i=0; i<copy_generals.length();i++){
        const General *general = copy_generals[i];
        QString general_name = general->objectName();
        QString name;
        name = Sanguosha->translate(general_name);
        QTableWidgetItem *name_item = new QTableWidgetItem(name);
        ui->tableWidget->setItem(i,1,name_item);
    }
    ui->tableWidget->setColumnWidth(0, 80);
    ui->tableWidget->setColumnWidth(1, 95);
    ui->tableWidget->setColumnWidth(2, 40);
    ui->tableWidget->setColumnWidth(3, 50);
    ui->tableWidget->setColumnWidth(4, 60);
    ui->tableWidget->setColumnWidth(5, 85);
    ui->tableWidget->setCurrentItem(ui->tableWidget->item(0,0));
}

GeneralOverview *GeneralOverview::getInstance(QWidget *main_window){
    if(Overview == NULL){
        Overview = new GeneralOverview(main_window);
    }
    return Overview;
}
