#include "clientsocket.h"
#include "serversocket.h"

ServerSocket::ServerSocket(QObject *parent)
{
    setParent(parent);
    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &ServerSocket::processNewConnection);
}

bool ServerSocket::listen(const QHostAddress &address, ushort port)
{
    return m_server->listen(address, port);
}

ushort ServerSocket::serverPort() const
{
    return m_server->serverPort();
}

void ServerSocket::processNewConnection() {
    QTcpSocket *socket = m_server->nextPendingConnection();
    ClientSocket *connection = new ClientSocket(socket);
    emit newConnection(connection);
}
