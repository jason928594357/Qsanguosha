#include "qsanselectableitem.h"

#include <QImageReader>
#include <QMessageBox>

QSanSelectableItem::QSanSelectableItem(const QString &filename, bool center_as_origin){
    load(filename, center_as_origin);
}

bool QSanSelectableItem::load(const QString &filename, bool center_as_origin){
    return _load(filename, QSize(), false, center_as_origin);
}

bool QSanSelectableItem::_load(const QString &filename, QSize newSize, bool useNewSize, bool center_as_origin){
    bool success = _m_mainPixmap.load(filename);
    if(!success){
        QImageReader reader(filename);
        QString error_string = reader.errorString();
        QString warning = tr("Can not load image %1[%2], error string is %3")
                .arg(filename).arg(metaObject()->className()).arg(error_string);
        QMessageBox::warning(NULL, tr("Warning"), warning);
    }else{
        if(useNewSize){
            _m_width = newSize.width();
            _m_height = newSize.height();
        }else{
            _m_width = _m_mainPixmap.width();
            _m_height = _m_mainPixmap.height();
        }
        if(center_as_origin){
            resetTransform();
            setTransform(QTransform::fromTranslate(-_m_width / 2, -_m_height / 2), true);
        }else{
            this->prepareGeometryChange();
        }
    }
    return success;
}

QRectF QSanSelectableItem::boundingRect() const
{
    return QRectF(0, 0, _m_width, _m_height);
}

void QSanSelectableItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(QRect(0, 0, _m_width, _m_height), _m_mainPixmap);
}

QVariant QSanSelectableItem::itemChange(GraphicsItemChange change, const QVariant &value){
    return QGraphicsObject::itemChange(change, value);
}
