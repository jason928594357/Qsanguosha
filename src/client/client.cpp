#include "client.h"

using namespace QSanProtocol;

Client *ClientInstance = NULL;

Client::Client(QObject *parent, const QString &filename)
    : QObject(parent), m_isDiscardActionRefusable(true),
       status(NotActive), alive_count(1), swap_pile(0),
       _m_roomState(true)
{
    ClientInstance = this;
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
