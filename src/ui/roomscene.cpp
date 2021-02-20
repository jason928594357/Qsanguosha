#include "roomscene.h"
#include "protocol.h"

using namespace QSanProtocol;

RoomScene *RoomSceneInstance;

RoomScene::RoomScene(QMainWindow *main_window)
    : game_started(false), main_window(main_window)
{
    RoomSceneInstance = this;
}

RoomScene::~RoomScene()
{
    if (RoomSceneInstance == this) {
        RoomSceneInstance = NULL;
    }
}
