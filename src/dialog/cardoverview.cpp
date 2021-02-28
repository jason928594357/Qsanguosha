#include "cardoverview.h"
#include "ui_cardoverview.h"

static CardOverview *Overview;

CardOverview *CardOverview::getInstance(QWidget *main_window)
{
    if (Overview == NULL)
        Overview = new CardOverview(main_window);

    return Overview;
}

CardOverview::CardOverview(QWidget *parent){

}
