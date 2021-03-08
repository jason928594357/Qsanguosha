#ifndef GENERALOVERVIEW_H
#define GENERALOVERVIEW_H

#include "general.h"

#include <QDialog>
#include <QVBoxLayout>

namespace Ui {
class GeneralOverview;
}
class GeneralOverview : public QDialog
{
public:
    GeneralOverview(QWidget *parent = 0);
    ~GeneralOverview();
    void fillGenrals(const QList<const General *> &generals, bool init = true);
    static GeneralOverview *getInstance(QWidget *main_window);
private:
    Ui::GeneralOverview *ui;
    QVBoxLayout *button_layout;
    QString origin_window_title;
    QList<const General *> all_generals;
};

#endif // GENERALOVERVIEW_H
