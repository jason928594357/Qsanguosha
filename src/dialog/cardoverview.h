#ifndef CARDOVERVIEW_H
#define CARDOVERVIEW_H

#include "card.h"

#include <QDialog>
#include <QTableWidgetItem>

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

private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *);
    void on_tableWidget_itemSelectionChanged();
    void on_malePlayButton_clicked();
    void on_femalePlayButton_clicked();
};

#endif // CARDOVERVIEW_H
