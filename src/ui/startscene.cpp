#include "startscene.h"
#include "settings.h"

StartScene::StartScene()
{
    logo = new QSanSelectableItem("image/logo/logo.png", true);
    logo->moveBy(0, -Config.Rect.height() / 4.8);
    addItem(logo);


}

StartScene::~StartScene()
{
    delete logo;
    logo = NULL;
    foreach (Button *b, buttons) {
        delete b;
        b = NULL;
    }
}

void StartScene::addButton(QAction *action)
{
    Button *button = new Button(action->text());
    button->setMute(false);
    connect(button, SIGNAL(clicked()), action, SLOT(trigger()));
    addItem(button);
    QRectF rect = button->boundingRect();
    int n = buttons.length();
    if (n < 4){
        button->setPos(-rect.width() - 4, (n - 0.5) * (rect.height() * 1.2));
    }else{
        button->setPos(4, (n - 4.5) * (rect.height() * 1.2));
    }
    buttons << button;
}
