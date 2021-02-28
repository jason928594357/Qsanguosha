﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startscene.h"
#include "settings.h"
#include "roomscene.h"

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

    scene = start_scene;
    FitView *view = new FitView(scene);

    setCentralWidget(view);
    restoreFromConfig();
}

void MainWindow::restoreFromConfig(){
    resize(Config.value("WindowSize").toSize());
    move(Config.value("WindowPosition").toPoint());
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
