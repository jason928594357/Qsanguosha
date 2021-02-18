#ifndef GENERALOVERVIEW_H
#define GENERALOVERVIEW_H

#include "flatdialog.h"
#include <QModelIndex>

class General;

namespace Ui {
class GeneralOverview;
}

class GeneralOverview : public FlatDialog
{
    Q_OBJECT

public:
    GeneralOverview(QWidget *parent = 0);
    ~GeneralOverview();
    void fillGenerals(const QList<const General *> &generals, bool init = true);
    static GeneralOverview *getInstance(QWidget *main_window);

private:
    Ui::GeneralOverview *ui;
    QMap<const General *, int> *all_generals;
};

#endif // GENERALOVERVIEW_H
