#ifndef LOBBYSCENE_H
#define LOBBYSCENE_H

#include <QGraphicsScene>
#include <QMainWindow>

class Client;

class LobbyScene:public QGraphicsScene {
    Q_OBJECT
public:
    explicit LobbyScene(QMainWindow *parent = 0);
    ~LobbyScene();
signals:
    void roomSelected();
    void createRoomClicked();
    void exit();

private:
    int currentPage;
    Client *client;
};

#endif // LOBBYSCENE_H
