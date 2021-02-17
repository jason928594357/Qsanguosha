#ifndef ABSTRACTCLIENTSOCKET_H
#define ABSTRACTCLIENTSOCKET_H

#include <QHostAddress>
#include <QObject>

class AbstractClientSocket: public QObject {
    Q_OBJECT
public:
    virtual void connectToHost(const QString &address) = 0;
    virtual void connectToHost(const QHostAddress &address, ushort port) = 0;
    virtual void disconnectFromHost() = 0;
    virtual void send(const QByteArray &message) = 0;
    virtual bool isConnected() const = 0;
    virtual QString peerName() const = 0;
    virtual QString peerAddress() const = 0;
    virtual ushort peerPort() const = 0;

signals:
    void messageGot(const QByteArray &msg);
    void errorMessage(const QString &msg);
    void disconnected();
    void connected();
};

#endif // ABSTRACTCLIENTSOCKET_H
