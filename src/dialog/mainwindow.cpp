#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startScene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    StartScene *start_scene = new StartScene(this);
    QList<QAction *> actions;
    actions << ui -> actionStart_Game
            << ui -> actionStart_server;
    foreach(QAction *action,actions)
        start_scene ->addButton(action);
}

MainWindow::~MainWindow()
{
    delete ui;
}
