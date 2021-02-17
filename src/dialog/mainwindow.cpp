#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startScene.h"
#include "connectiondialog.h"
#include "server.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connection_dialog = new ConnectionDialog(this);
    connect(ui->actionStart_Game, &QAction::triggered, connection_dialog, &ConnectionDialog::exec);
    connect(connection_dialog, &ConnectionDialog::accepted, this, &MainWindow::startConnection);
    StartScene *start_scene = new StartScene(this);
    QList<QAction *> actions;
    actions << ui -> actionStart_Game
            << ui -> actionStart_server;
    foreach(QAction *action,actions)
        start_scene ->addButton(action);
}

void MainWindow::startConnection(){

}

MainWindow::~MainWindow()
{
    delete ui;
}

BroadcastBox::BroadcastBox(Server *server,QWidget *parent)
    :QDialog(parent), server(server){
    setWindowTitle(tr("Broadcast"));
}

void BroadcastBox::accept() {
    QDialog::accept();
    //server->broadcastSystemMessage(text_edit->toPlainText());
}
