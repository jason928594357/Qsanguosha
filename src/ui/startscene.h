#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "qsanselectableitem.h"
#include "button.h"

#include <QGraphicsScene>
#include <QAction>

class StartScene: public QGraphicsScene{
    Q_OBJECT
public:
    StartScene();
    ~StartScene();
    void addButton(QAction *action);
private:
    QSanSelectableItem *logo;
    QList<Button *> buttons;
};

#endif // STARTSCENE_H
