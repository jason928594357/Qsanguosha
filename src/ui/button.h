#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsObject>
#include <QFont>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QRectF>

class Button:public QGraphicsObject {
    Q_OBJECT
public:
    explicit Button(const QString &label, qreal scale = 1.0);
    ~Button();
    void setMute(bool mute);
    virtual QRectF boundingRect() const;
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QString label;
    QSizeF size;
    bool mute;
    QFont font;
    QImage outimg;
    QPixmap title;
    QGraphicsPixmapItem *title_item;
    int glow;
    int timer_id;

    QGraphicsDropShadowEffect *de;
    QGraphicsDropShadowEffect *effect;

    void init();
};

#endif // BUTTON_H
