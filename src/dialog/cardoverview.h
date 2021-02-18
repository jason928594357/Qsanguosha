#ifndef CARDOVERVIEW_H
#define CARDOVERVIEW_H


#include "flatdialog.h"

namespace Ui {
    class CardOverview;
}

class CardOverview : public FlatDialog
{
    Q_OBJECT

public:
    CardOverview(QWidget *parent = 0);
    ~CardOverview();

private:
    Ui::CardOverview *ui;
};

#endif // CARDOVERVIEW_H
