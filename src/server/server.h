#ifndef SERVER_H
#define SERVER_H

#include "abstractserversocket.h"
#include "protocol.h"

#include <QObject>
#include <QHostAddress>

class Server : public QObject{
    Q_OBJECT
public:
    friend class BanIpDialog;
    enum Role {
        LobbyRole,
        RoomRole
    };
    explicit Server(QObject *parent, Role role = RoomRole);
    Role getRole() const {
        return role;
    }
    void broadcastSystemMessage(const QString &msg);
    bool listen(const QHostAddress &address, ushort port) {
        return server->listen(address, port);
    }
    void daemonize();
    void connectToLobby();

protected slots:
    void processMessage(const QByteArray &message);
protected:
    void checkVersion(const QVariant &server_version);
    void forwardLobbyMessage(const QVariant &message);
    void replyServerName(const QByteArray &, const QHostAddress &from, ushort port);
    void replyPlayerNum(const QByteArray &, const QHostAddress &from, ushort port);

    Role role;
    AbstractServerSocket *server;
    AbstractClientSocket *lobby;

    typedef void (Server::*LobbyFunction)(const QVariant &);
    static QHash<QSanProtocol::CommandType, LobbyFunction> lobbyFunctions;

    typedef void (Server::*RoomFunction)(AbstractClientSocket *socket, const QVariant &);
    static QHash<QSanProtocol::CommandType, RoomFunction> roomFunctions;

    typedef void (Server::*ServiceFunction)(const QByteArray &, const QHostAddress &, ushort);
    static QHash<QSanProtocol::ServiceType, ServiceFunction> serviceFunctions;

private:
    void initLobbyFunctions();
    void initRoomFunctions();
};

#endif // SERVER_H
