#ifndef ROOMSCENE_H
#define ROOMSCENE_H

#include <QGraphicsScene>
#include <QMainWindow>

class RoomScene:public QGraphicsScene {
    Q_OBJECT
public:
    RoomScene(QMainWindow *main_window);
    ~RoomScene();

    bool game_started;
private:
    QMainWindow *main_window;
};

#endif // ROOMSCENE_H
