#include "lobbyscene.h"
#include "client.h"

#include <QVBoxLayout>

LobbyScene::LobbyScene(QMainWindow *parent) :
    QGraphicsScene(parent), currentPage(0), client(ClientInstance)
{
    setItemIndexMethod(NoIndex);

    chatBox = new QTextEdit;
    chatBox->setObjectName("chat_log");
    chatBox->setReadOnly(true);
    chatLineEdit = new QLineEdit;
    chatLineEdit->setObjectName("chat_input");
    QVBoxLayout *chatLayout = new QVBoxLayout;
    chatLayout->addWidget(chatBox);
    chatLayout->addWidget(chatLineEdit);
    chatWidget = new QWidget;
    chatWidget->setObjectName("lobby_chat_box");
    chatWidget->setLayout(chatLayout);
    addWidget(chatWidget);
    connect(client, &Client::lineSpoken, chatBox, &QTextEdit::append);
    connect(chatLineEdit, &QLineEdit::editingFinished, this, &LobbyScene::speakToServer);
}

LobbyScene::~LobbyScene(){
    if(client && ClientInstance != client){
        client -> deleteLater();
    }
}

void LobbyScene::speakToServer(){
    if(client == NULL){
        return;
    }
    QString message = chatLineEdit->text();
    if(!message.isEmpty()){
        client->speakToServer(message);
        chatLineEdit->clear();
    }
}


