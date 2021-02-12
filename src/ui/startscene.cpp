#include "startscene.h"
#include "server.h"
#include <QGraphicsScene>
#include <QAction>

StartScene::StartScene(QObject *parent){

}

void StartScene::addButton(QAction *action){
    QString icon = action->objectName();
    icon.remove(0,6);
}
