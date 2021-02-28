#include "roomscene.h"

RoomScene::RoomScene(QMainWindow *main_window)
    : main_window(main_window), game_started(false), m_tableBgPixmap(1, 1), m_tableBgPixmapOrig(1, 1)
{
    setParent(main_window);
}

RoomScene::~RoomScene(){

}

void RoomScene::adjustItems(){

}
