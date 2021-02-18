#include "udpsocket.h"

#include <QUdpSocket>

UdpSocket::UdpSocket(QObject *parent)
    : m_socket(new QUdpSocket(this))
{
    setParent(parent);
}
