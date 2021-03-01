#ifndef CARDOVERVIEW_H
#define CARDOVERVIEW_H

#include <QDialog>

namespace Ui {
class CardOverview;
}
class CardOverview :public QDialog{
    Q_OBJECT
public:
    static CardOverview *getInstance(QWidget *main_window);
    CardOverview(QWidget *parent = 0);
    void loadFromAll();
    ~CardOverview();
private:
    Ui::CardOverview *ui;
};

#endif // CARDOVERVIEW_H
