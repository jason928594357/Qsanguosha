#include "flatdialog.h"

#include <QLabel>
#include <QPainter>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QPushButton>

FlatDialog::FlatDialog(QWidget *parent, bool initialLayoutWithTitle)
    : QDialog(parent)
{
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    mousePressed = false;
    if(initialLayoutWithTitle){
        layout = new QVBoxLayout;
        title = new QLabel;
        title->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        title->setObjectName("window_title");
        connect(this, &FlatDialog::windowTitleChanged, title, &QLabel::setText);
        layout->addWidget(title);
        setLayout(layout);
    }
}

bool FlatDialog::addCloseButton(QString name){
    if (layout == NULL){
        return false;
    }
    if (name.isEmpty()){
        name = tr("Close");
    }
    QPushButton *closeButton = new QPushButton(name);
    connect(closeButton, &QPushButton::clicked, this, &FlatDialog::reject);
    layout->addWidget(closeButton);
    return true;
}

void FlatDialog::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect(), 5, 5);
}

void FlatDialog::mousePressEvent(QMouseEvent *event){
    if (event->button() & Qt::LeftButton) {
        mousePressedPoint = event->globalPos() - frameGeometry().topLeft();
        mousePressed = true;
    }
}

void FlatDialog::mouseMoveEvent(QMouseEvent *event){
    if(mousePressed){
        move(event->globalPos() - mousePressedPoint);
    }
}

void FlatDialog::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() & Qt::LeftButton){
        mousePressed = false;
    }
}
