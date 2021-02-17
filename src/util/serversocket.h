#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "abstractserversocket.h"

#include <QTcpServer>

class QTcpServer;

class ServerSocket : public AbstractServerSocket {
    Q_OBJECT
public:
    ServerSocket(QObject *parent = 0);
    virtual bool listen(const QHostAddress &address, ushort port = 0);
    virtual ushort serverPort() const;

private slots:
    void processNewConnection();

private:
    QTcpServer *m_server;
};

#endif // SERVERSOCKET_H
