#include "skinbank.h"

QSanSkinFactory &QSanSkinFactory::getInstance(){

}

QPixmap QSanRoomSkin::getGeneralPixmap(const QString &generalName, GeneralIconSize size, const int skinId) const{

}

const QSanSkinScheme &QSanSkinFactory::getCurrentSkinScheme() {
    return this->_sm_currentSkin;
}

const QSanRoomSkin &QSanSkinScheme::getRoomSkin() const{
    return _m_roomSkin;
}
