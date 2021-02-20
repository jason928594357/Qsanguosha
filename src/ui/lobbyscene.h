#ifndef LOBBYSCENE_H
#define LOBBYSCENE_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>

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

private slots:
    void speakToServer();
private:
    QWidget *chatWidget;
    QLineEdit *chatLineEdit;
    QTextEdit *chatBox;
    int currentPage;
    Client *client;
};

#endif // LOBBYSCENE_H
