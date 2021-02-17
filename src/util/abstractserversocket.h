#ifndef ABSTRACTSERVERSOCKET_H
#define ABSTRACTSERVERSOCKET_H

#include <QHostAddress>
#include <QObject>

class AbstractClientSocket;

class AbstractServerSocket:public QObject {
    Q_OBJECT
public:
    virtual bool listen(const QHostAddress &address, ushort port = 0) = 0;
    virtual ushort serverPort() const = 0;
signals:
    void newConnection(AbstractClientSocket *connection);
};

#endif // ABSTRACTSERVERSOCKET_H
