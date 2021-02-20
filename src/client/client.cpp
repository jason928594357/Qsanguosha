#include "client.h"
#include "protocol.h"

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

    }
    recorder = NULL;
    if(!filename.isEmpty()){
        socket = NULL;
        replayer = new Replayer(filename, this);
    }
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
