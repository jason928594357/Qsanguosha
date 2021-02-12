#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QGraphicsScene>
#include <QAction>

class StartScene : public QGraphicsScene{
    Q_OBJECT
public:
    StartScene(QObject *parent =0);

    void addButton(QAction *action);

};
#endif // STARTSCENE_H
