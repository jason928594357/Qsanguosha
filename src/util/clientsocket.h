#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include "abstractclientsocket.h"

class QTcpSocket;
class QTimer;

class ClientSocket : public AbstractClientSocket{
    Q_OBJECT
public:
    ClientSocket(QObject *parent = 0);
    ClientSocket(QTcpSocket *socket, QObject *parent = 0);

    virtual void connectToHost(const QString &address);
    virtual void connectToHost(const QHostAddress &address, ushort port);
    virtual void disconnectFromHost();
    virtual void send(const QByteArray &message);
    virtual bool isConnected() const;
    virtual QString peerName() const;
    virtual QString peerAddress() const;
    virtual ushort peerPort() const;

private slots:
    void getMessage();
    void raiseError(QAbstractSocket::SocketError socketError);
    void keepAlive();
    void checkConnectionState();

private:
    enum PacketType {
        UnknownPacket,
        InlineTextPacket,       // Texts ended with '\n'
        KeepAlivePacket,        // Checking the peer's state
        AcknowledgePacket
    };

    void init();

    QTcpSocket *const m_socket;
    bool m_isAlive;
    QTimer *m_keepAliveTimer;

    static const qint64 KEEP_ALIVE_INTERVAL;
    static const qint64 TIMEOUT_LIMIT;
};

#endif // CLIENTSOCKET_H
