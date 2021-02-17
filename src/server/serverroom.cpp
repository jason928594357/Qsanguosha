#include "server.h"
#include "clientsocket.h"
#include "settings.h"

using namespace QSanProtocol;

void Server::initLobbyFunctions(){
    lobbyFunctions[S_COMMAND_CHECK_VERSION] = &Server::checkVersion;
    lobbyFunctions[S_COMMAND_SPEAK] = &Server::forwardLobbyMessage;

    serviceFunctions[S_SERVICE_DETECT_SERVER] = &Server::replyServerName;
    serviceFunctions[S_SERVICE_PLAYER_NUM] = &Server::replyPlayerNum;
}

void Server::connectToLobby(){
    if (Config.LobbyAddress.isEmpty()){
        return;
    }
    lobby = new ClientSocket(this);
    connect(lobby, &ClientSocket::messageGot, this, &Server::processMessage);
    lobby->connectToHost(Config.LobbyAddress);
}

void Server::checkVersion(const QVariant &server_version){

}

void Server::forwardLobbyMessage(const QVariant &message){

}

void Server::replyServerName(const QByteArray &, const QHostAddress &from, ushort port){

}

void Server::replyPlayerNum(const QByteArray &, const QHostAddress &from, ushort port){

}
