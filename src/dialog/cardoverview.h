#ifndef CARDOVERVIEW_H
#define CARDOVERVIEW_H

#include "card.h"

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
    void addCard(int i, const Card *card);
};

#endif // CARDOVERVIEW_H
