#include "lobbyscene.h"
#include "client.h"

LobbyScene::LobbyScene(QMainWindow *parent) :
    QGraphicsScene(parent), currentPage(0), client(ClientInstance)
{

}

LobbyScene::~LobbyScene(){
    if(client && ClientInstance != client){
        client -> deleteLater();
    }
}
