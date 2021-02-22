#include "startscene.h"
#include "settings.h"
#include "audio.h"
#include "qsanselectableitem.h"
#include "server.h"

#include <QPropertyAnimation>
#include <QGraphicsScale>
#include <QGraphicsScene>
#include <QAction>
#include <QParallelAnimationGroup>


StartScene::StartScene(QObject *parent)
    : QGraphicsScene(parent), server(NULL)
{
    logo = new QSanSelectableItem("image/logo/logo.png", true);
    shouldMourn = false;

    logo->moveBy(-Config.Rect.width()/4,0);
    addItem(logo);
    serverLog = NULL;

    setBackgroundBrush(QBrush(QPixmap(Config.BackgroundImage)));
    connect(this, &StartScene::sceneRectChanged, this, &StartScene::onSceneRectChanged);
}

void StartScene::addButton(QAction *action){
    QString icon = action->objectName();
    icon.remove(0,6);
}

void StartScene::switchToServer(Server *server){
    Audio::quit();
    logo->load("image/logo/logo-server.png");
    logo->setToolTip(QString());
    QPropertyAnimation *logoShift = new QPropertyAnimation(logo, "pos");
    logoShift->setEndValue(QPointF(Config.Rect.center().rx() - 330, Config.Rect.center().ry() - 215));

    QGraphicsScale *scale = new QGraphicsScale;
    scale->setXScale(1);
    scale->setYScale(1);
    QList<QGraphicsTransform *> transformations;
    transformations << scale;
    logo->setTransformations(transformations);

    QPropertyAnimation *xScale = new QPropertyAnimation(scale, "xScale");
    xScale->setEndValue(0.5);

    QPropertyAnimation *yScale = new QPropertyAnimation(scale, "yScale");
    yScale->setEndValue(0.5);

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(logoShift);
    group->addAnimation(xScale);
    group->addAnimation(yScale);
    group->start(QAbstractAnimation::DeleteWhenStopped);

    //foreach (Button *button, buttons) {
    //    button->hide();
    //}
    serverLog = new QTextEdit;
    serverLog->setReadOnly(true);
    serverLog->resize(700,420);
    serverLog->move(-400,-180);
    serverLog->setFrameShape(QFrame::NoFrame);

    addWidget(serverLog);

    this->server = server;

}

void StartScene::onSceneRectChanged(const QRectF &rect){

}
