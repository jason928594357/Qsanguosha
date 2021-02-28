#ifndef QSANSELECTABLEITEM_H
#define QSANSELECTABLEITEM_H

#include <QGraphicsObject>
#include <QPainter>

class QSanSelectableItem:public QGraphicsObject{
    Q_OBJECT
public:
    QSanSelectableItem(const QString &filename, bool center_as_origin = false);
    virtual QRectF boundingRect() const;
    bool load(const QString &filename, bool center_as_origin = false);
protected:
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int _m_width, _m_height;
    QPixmap _m_mainPixmap;
private:
    bool _load(const QString &filename, QSize newSize, bool useNewSize, bool center_as_origin);
};

#endif // QSANSELECTABLEITEM_H
