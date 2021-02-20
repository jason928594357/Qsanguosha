#include "client.h"
#include "protocol.h"
#include "clientsocket.h"
#include "settings.h"
#include "udpsocket.h"

using namespace QSanProtocol;

Client *ClientInstance = NULL;

QHash<CommandType, Client::Callback> Client::callbacks;

Client::Client(QObject *parent, const QString &filename)
    : QObject(parent), m_isDiscardActionRefusable(true),
      status(NotActive), alive_count(1), swap_pile(0),
      _m_roomState(true)
{
    ClientInstance = this;
    m_isGameOver = false;
    m_noNullificationThisTime = false;
    m_noNullificationTrickName = ".";
    if(callbacks.isEmpty()){
        callbacks[S_COMMAND_CHECK_VERSION] = &Client::checkVersion;
    }
    recorder = NULL;
    if(!filename.isEmpty()){
        socket = NULL;
        replayer = new Replayer(filename, this);
    }else {
        socket = new ClientSocket(this);
        connect(socket, &ClientSocket::messageGot, this, &Client::processServerPacket);
        QHostAddress address(QHostAddress::LocalHost);
        ushort port = 9527u;
        if(Config.HostAddress.contains(QChar(':'))){
            QStringList texts = Config.HostAddress.split(QChar(':'));
            address.setAddress(texts.value(0));
            port = texts.value(1).toUShort();
        }else{
            address.setAddress(Config.HostAddress);
            if(address.isLoopback()){
                port = Config.ServerPort;
            }
        }
        socket->connectToHost(address,port);
        replayer = NULL;
    }
    lines_doc = new QTextDocument(this);
    prompt_doc = new QTextDocument(this);
    prompt_doc->setTextWidth(350);
    prompt_doc->setDefaultFont(QFont("SimHei"));
    detector = new UdpSocket(this);
    connect(detector, &AbstractUdpSocket::newDatagram, this, &Client::processDatagram);
}

void Client::processServerPacket(const QByteArray &cmd){

}

void Client::processDatagram(const QByteArray &data, const QHostAddress &from, ushort port){
    qDebug("123");
}

Client::~Client() {
    if (ClientInstance == this){
        ClientInstance = NULL;
    }
}

void Client::setStatus(Status status){
    Status old_status = this->status;
    this->status = status;
    if(status == Client::Playing){

    }
}

Client::Status Client::getStatus() const{
    return status;
}

void Client::speakToServer(const QString &text){
    if(text.isEmpty()){
        return;
    }
    notifyServer(S_COMMAND_SPEAK, text);
}

void Client::notifyServer(CommandType command, const QVariant &arg) {
    if (socket) {
        //Packet packet(S_SRC_CLIENT | S_TYPE_NOTIFICATION | S_DEST_ROOM, command);
        //packet.setMessageBody(arg);
        //socket->send(packet.toJson());
    }
}

void Client::checkVersion(const QVariant &server_version){
    qDebug("client checkVersion");
}
