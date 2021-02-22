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

void UdpSocket::writeDatagram(const QByteArray &data, const QString &to){
    QHostAddress address(QHostAddress::Broadcast);
    ushort port = 0;
    if(to.contains(QChar(':'))){
        QStringList texts = to.split(QChar(':'));
        address.setAddress(texts.at(0));
        port = texts.at(1).toUShort();
    }else{
        address.setAddress(to);
    }
    m_socket ->writeDatagram(data,address,port);
}

void UdpSocket::writeDatagram(const QByteArray &data, const QHostAddress &to, ushort port){
    m_socket->writeDatagram(data, to, port);
}

void UdpSocket::processNewDatagram(){
    while(m_socket->hasPendingDatagrams()){
        QHostAddress from;
        QByteArray data;
        quint16 port;
        data.resize(m_socket->pendingDatagramSize());
        m_socket->readDatagram(data.data(), data.size(), &from, &port);
        emit newDatagram(data, from, port);
    }
}
