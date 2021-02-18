#ifndef ABSTRACTUDPSOCKET_H
#define ABSTRACTUDPSOCKET_H

#include <QHostAddress>

class AbstractUdpSocket : public QObject {
    Q_OBJECT
public:
    virtual void bind(const QHostAddress &address, ushort port) = 0;
signals:
    void newDatagram(const QByteArray &data, const QHostAddress &from, ushort port);
};
#endif // ABSTRACTUDPSOCKET_H
