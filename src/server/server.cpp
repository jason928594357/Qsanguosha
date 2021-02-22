#include "server.h"
#include "serversocket.h"
#include "udpsocket.h"
#include "clientstruct.h"
#include "settings.h"

using namespace QSanProtocol;

QHash<CommandType, Server::LobbyFunction> Server::lobbyFunctions;
QHash<CommandType, Server::RoomFunction> Server::roomFunctions;
QHash<ServiceType, Server::ServiceFunction> Server::serviceFunctions;

Server::Server(QObject *parent, Role role)
    : QObject(parent),  role(role), server(new ServerSocket),
      current(NULL), lobby(NULL), daemon(NULL)
{
    server->setParent(this);
    if(lobbyFunctions.isEmpty()){
        initLobbyFunctions();
    }
    if(roomFunctions.isEmpty()){
        initRoomFunctions();
    }
    ServerInfo = RoomInfoStruct(SettingsInstance);

}

void Server::broadcastSystemMessage(const QString &msg){

}

void Server::initRoomFunctions(){

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
