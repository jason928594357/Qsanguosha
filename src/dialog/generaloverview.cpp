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

static GeneralOverview *Overview;

GeneralOverview *GeneralOverview::getInstance(QWidget *main_window) {
    if (Overview == NULL)
        Overview = new GeneralOverview(main_window);

    return Overview;
}

void GeneralOverview::fillGenerals(const QList<const General *> &generals, bool init){

}
