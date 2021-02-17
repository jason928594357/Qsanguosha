#ifndef SERVER_H
#define SERVER_H

#include "abstractserversocket.h"

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
protected:
    Role role;
    AbstractServerSocket *server;
};

#endif // SERVER_H
