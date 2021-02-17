#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startScene.h"
#include "connectiondialog.h"
#include "server.h"
#include "serverdialog.h"
#include "settings.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

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
            << ui -> actionStart_Server;
    foreach(QAction *action,actions)
        start_scene ->addButton(action);
}

void MainWindow::on_actionStart_Server_triggered(){
    ServerDialog *dialog = new ServerDialog(this);
    if(!dialog ->config()){
        return;
    }
    server = new Server(this);
    if (!server->listen(QHostAddress::Any, Config.ServerPort)) {
        QMessageBox::warning(this, tr("Warning"), tr("Can not start server!"));
        server->deleteLater();
        server = NULL;
        return;
    }

    if (Config.ConnectToLobby){
        server->connectToLobby();
    }
    server->daemonize();

    ui->actionStart_Game->disconnect();
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
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel(tr("Please input the message to broadcast")));

    text_edit = new QTextEdit;
    layout->addWidget(text_edit);
}

void BroadcastBox::accept() {
    QDialog::accept();
    server->broadcastSystemMessage(text_edit->toPlainText());
}
