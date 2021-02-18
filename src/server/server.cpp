#include "server.h"
#include "serversocket.h"
#include "udpsocket.h"

using namespace QSanProtocol;

QHash<CommandType, Server::LobbyFunction> Server::lobbyFunctions;
QHash<CommandType, Server::RoomFunction> Server::roomFunctions;
QHash<ServiceType, Server::ServiceFunction> Server::serviceFunctions;

Server::Server(QObject *parent, Role role)
{
    server->setParent(this);
    if(lobbyFunctions.isEmpty()){
        initLobbyFunctions();
    }
}

void Server::broadcastSystemMessage(const QString &msg){

}

void Server::daemonize(){
    daemon = new UdpSocket(this);
    daemon ->bind(QHostAddress::Any,serverPort());
    connect(daemon, &AbstractUdpSocket::newDatagram, this, &Server::processDatagram);
}

void Server::processMessage(const QByteArray &message){

}

void Server::processDatagram(const QByteArray &data, const QHostAddress &from, ushort port){

}
