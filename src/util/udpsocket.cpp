#include "udpsocket.h"

#include <QUdpSocket>

UdpSocket::UdpSocket(QObject *parent)
    : m_socket(new QUdpSocket(this))
{
    setParent(parent);
    connect(m_socket, &QUdpSocket::readyRead, this, &UdpSocket::processNewDatagram);
}


void UdpSocket::bind(const QHostAddress &address, ushort port)
{
    m_socket->bind(address, port);
}

void UdpSocket::processNewDatagram(){

}

void UdpSocket::writeDatagram(const QByteArray &data, const QString &to){

}

void UdpSocket::writeDatagram(const QByteArray &data, const QHostAddress &to, ushort port){

}
