#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "configdialog.h"
#include "engine.h"

#include <QMainWindow>
#include <QDialog>
#include <QTextEdit>
#include<QSystemTrayIcon>

namespace Ui {
    class MainWindow;
}

class FitView;
class QGraphicsScene;
class Server;
class QTextEdit;
class ConnectionDialog;


class BroadcastBox : public QDialog {
    Q_OBJECT

public:
    BroadcastBox(Server *server, QWidget *parent = 0);
protected:
    virtual void accept();
private:
    Server *server;
    QTextEdit *text_edit;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    FitView *view;
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    ConnectionDialog *connection_dialog;
    Server *server;
    ConfigDialog *config_dialog;
    QSystemTrayIcon *systray;

public slots:
    void startConnection();

private slots:
    void on_actionStart_Server_triggered();
    void on_actionGeneral_Overview_triggered();
    void on_actionMinimize_to_system_tray_triggered();
    void checkVersion(const QString &server_version, const QString &server_mod);
    void enterLobby();
    void gotoScene(QGraphicsScene *scene);
    void exitScene();
    void onCreateRoomClicked();

    void startGameInAnotherInstance();
};



#endif // MAINWINDOW_H
