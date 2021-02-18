#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "abstractudpsocket.h"

class QUdpSocket;
class UdpSocket :public AbstractUdpSocket {
    Q_OBJECT
public:
    UdpSocket(QObject *parent = 0);
private:
    QUdpSocket *m_socket;
};

#endif // UDPSOCKET_H
