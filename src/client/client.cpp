#include "client.h"

using namespace QSanProtocol;

Client *ClientInstance = NULL;

Client::Client(QObject *parent, const QString &filename)
{
    ClientInstance = this;
}

Client::~Client() {
    if (ClientInstance == this){
        ClientInstance = NULL;
    }
}

void Client::setStatus(Status status){

}

Client::Status Client::getStatus() const{
    return status;
}
