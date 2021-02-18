#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "abstractudpsocket.h"

class QUdpSocket;
class UdpSocket :public AbstractUdpSocket {
    Q_OBJECT
public:
    UdpSocket(QObject *parent = 0);

    virtual void bind(const QHostAddress &address, ushort port);
    virtual void writeDatagram(const QByteArray &data, const QString &to);
    virtual void writeDatagram(const QByteArray &data, const QHostAddress &to, ushort port);

private slots:
    void processNewDatagram();

private:
    QUdpSocket *m_socket;
};

#endif // UDPSOCKET_H
