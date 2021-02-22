#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "server.h"
#include "qsanselectableitem.h"

#include <QGraphicsScene>
#include <QAction>
#include <QTextEdit>

class Server;

class StartScene : public QGraphicsScene{
    Q_OBJECT
public:
    StartScene(QObject *parent =0);

    void addButton(QAction *action);
    void switchToServer(Server *server);

private slots:
    void onSceneRectChanged(const QRectF &rect);

private:
    QSanSelectableItem *logo;
    QTextEdit *serverLog;
    bool shouldMourn;
    Server *server;
};
#endif // STARTSCENE_H
