#ifndef GENERALOVERVIEW_H
#define GENERALOVERVIEW_H

#include <QDialog>

namespace Ui {
class GeneralOverview;
}
class GeneralOverview : public QDialog
{
public:
    GeneralOverview(QWidget *parent = 0);
    ~GeneralOverview();
    static GeneralOverview *getInstance(QWidget *main_window);
private:
    Ui::GeneralOverview *ui;
};

#endif // GENERALOVERVIEW_H
