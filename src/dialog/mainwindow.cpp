#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startScene.h"
#include "connectiondialog.h"
#include "server.h"
#include "serverdialog.h"
#include "settings.h"
#include "configdialog.h"
#include "generaloverview.h"
#include "lobbyscene.h"
#include "client.h"

#include <QGraphicsView>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

class FitView: public QGraphicsView {
public:
    FitView(QGraphicsView *scene) :QGraphicsView(scene) {
        setSceneRect(Config.Rect);
        setRenderHints(QPainter::TextAntialiasing | QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    }

    virtual void mousePressEvent(QMouseEvent *event) {

    }
    virtual void mouseMoveEvent(QMouseEvent *event) {
    }
    virtual void mouseReleaseEvent(QMouseEvent *event) {
    }
    virtual void resizeEvent(QResizeEvent *event){

    }
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connection_dialog = new ConnectionDialog(this);
    connect(ui->actionStart_Game, &QAction::triggered, connection_dialog, &ConnectionDialog::exec);


    connect(connection_dialog, &ConnectionDialog::accepted, this, &MainWindow::startConnection);

    config_dialog = new ConfigDialog(this);


    StartScene *start_scene = new StartScene(this);
    QList<QAction *> actions;
    actions << ui -> actionStart_Game
            << ui -> actionStart_Server
            << ui -> actionGeneral_Overview;
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

void MainWindow::on_actionGeneral_Overview_triggered(){
    GeneralOverview *overview = GeneralOverview::getInstance(this);
    overview->fillGenerals(Sanguosha->getGeneralList());
    overview->show();
}

void MainWindow::startConnection(){
    Client *client = new Client(this);
    connect(client, &Client::version_checked, this, &MainWindow::checkVersion);
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

void MainWindow::enterLobby(){
    if(!Config.HistoryIPs.contains(Config.HostAddress)){
        Config.HistoryIPs << Config.HostAddress;
        Config.HistoryIPs.sort();
        Config.setValue("HistoryIPs", Config.HistoryIPs);
    }

    LobbyScene *scene = new LobbyScene(this);
    connect(scene, &LobbyScene::createRoomClicked, this, &MainWindow::onCreateRoomClicked);
    connect(scene, (void (LobbyScene::*)())(&LobbyScene::roomSelected), this, &MainWindow::startConnection);
    connect(scene, &LobbyScene::exit, this, &MainWindow::exitScene);

    gotoScene(scene);
}

void MainWindow::checkVersion(const QString &server_version, const QString &server_mod){
    qDebug("checkV");
}

void MainWindow::onCreateRoomClicked(){
    bool hasGlobalIp = false;
}

void MainWindow::exitScene(){

}

void MainWindow::gotoScene(QGraphicsScene *scene){

}
