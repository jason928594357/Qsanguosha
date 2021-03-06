#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startscene.h"
#include "settings.h"
#include "roomscene.h"
#include "cardoverview.h"
#include "generaloverview.h"

#include <QMessageBox>
#include <QGraphicsView>
#include <QResizeEvent>
#include <QGLWidget>
#include <QTime>

class FitView : public QGraphicsView
{
public:
    FitView(QGraphicsScene *scene) : QGraphicsView(scene) {
        setSceneRect(Config.Rect);
        setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
    }

protected:
    void resizeEvent(QResizeEvent *event)
    {
        QGraphicsView::resizeEvent(event);
        MainWindow *main_window = qobject_cast<MainWindow *>(parentWidget());
        if(Config.FitInView){
            fitInView(sceneRect(), Qt::KeepAspectRatio);
        }
        if(main_window){
            main_window->setBackgroundBrush(true);
        }

    }
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Config.init();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    ui->setupUi(this);
    StartScene *start_scene = new StartScene;
    QList<QAction *> actions;
    actions << ui->actionStart_Game
            << ui->actionStart_Server
            << ui->actionReplay
            << ui->actionConfigure
            << ui->actionGeneral_Overview
            << ui->actionCard_Overview
            << ui->actionScenario_Overview
            << ui->actionAbout;
    foreach (QAction *action, actions) {
        start_scene->addButton(action);
    }
    scene = start_scene;
    FitView *view = new FitView(scene);

    setCentralWidget(view);
    restoreFromConfig();
}

void MainWindow::restoreFromConfig(){
    resize(Config.value("WindowSize").toSize());
    move(Config.value("WindowPosition").toPoint());
}

void MainWindow::closeEvent(QCloseEvent *)
{
    Config.setValue("WindowSize", size());
    Config.setValue("WindowPosition", pos());
    Config.setValue("WindowState", (int)windowState());
}

MainWindow::~MainWindow()
{
    delete ui;
    view->deleteLater();
    if(scene){
        scene->deleteLater();
    }
}

void MainWindow::on_actionExit_triggered(){
    QMessageBox::StandardButton result;
    result = QMessageBox::question(this,
                                   tr("Sanguosha"),
                                   tr("Are you sure to exit?"),
                                   QMessageBox::Ok | QMessageBox::Cancel);
    if(result == QMessageBox::Ok){
        close();
    }
}

void MainWindow::setBackgroundBrush(bool centerAsOrigin)
{
    if (scene) {
        QPixmap pixmap(Config.BackgroundImage);
        QBrush brush(pixmap);
        qreal sx = (qreal)width() / qreal(pixmap.width());
        qreal sy = (qreal)height() / qreal(pixmap.height());

        QTransform transform;
        if (centerAsOrigin)
            transform.translate(-(qreal)width() / 2, -(qreal)height() / 2);
        transform.scale(sx, sy);
        brush.setTransform(transform);
        scene->setBackgroundBrush(brush);
    }
}

void MainWindow::on_actionGeneral_Overview_triggered(){
    GeneralOverview *overview = GeneralOverview::getInstance(this);
    overview->show();
}

void MainWindow::on_actionCard_Overview_triggered(){
    CardOverview *overview = CardOverview::getInstance(this);
    overview->loadFromAll();
    overview->show();
}
