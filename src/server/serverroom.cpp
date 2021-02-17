#include "server.h"
#include "clientsocket.h"
#include "settings.h"

using namespace QSanProtocol;

void Server::connectToLobby(){
    if (Config.LobbyAddress.isEmpty()){
        return;
    }
    lobby = new ClientSocket(this);
    connect(lobby, &ClientSocket::messageGot, this, &Server::processMessage);
    lobby->connectToHost(Config.LobbyAddress);
}
