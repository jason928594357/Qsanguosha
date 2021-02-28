#ifndef ROOMSCENE_H
#define ROOMSCENE_H

#include <QGraphicsScene>
#include <QMainWindow>

class RoomScene:public QGraphicsScene{
    Q_OBJECT
public:
    RoomScene(QMainWindow *main_window);
    ~RoomScene();
    void adjustItems();
private:
    QMainWindow *main_window;
    bool game_started;
    QPixmap m_tableBgPixmap;
    QPixmap m_tableBgPixmapOrig;
};

#endif // ROOMSCENE_H
