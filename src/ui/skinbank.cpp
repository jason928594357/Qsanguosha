#include "skinbank.h"

#include <QFile>

using namespace JsonUtils;

const char *IQSanComponentSkin::S_SKIN_KEY_DEFAULT = "default";
const char *QSanRoomSkin::S_SKIN_KEY_GENERAL_CARD = "generalCard-%2-%1";
const char *QSanRoomSkin::S_SKIN_KEY_PLAYER_GENERAL_ICON = "playerGeneralIcon-%3-%2-%1";

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

bool QSanRoomSkin::generalHasSkin(const QString &general, const int skinId, const bool isCard) const{
    const QString id = QString::number(skinId);
    QString key;
    if(isCard){
        key = S_SKIN_KEY_GENERAL_CARD;
    }else{
        key = QString(S_SKIN_KEY_PLAYER_GENERAL_ICON).arg(S_GENERAL_ICON_SIZE_HERO_SKIN);
    }
    QString totalKey = key.arg(id).arg(general);
    if(isImageKeyDefined(totalKey)){
        return QFile::exists(_m_imageConfig.value(totalKey).toString());
    }
    totalKey = key.arg(id).arg(S_SKIN_KEY_DEFAULT);
    if(isImageKeyDefined(totalKey)){
        return QFile::exists(QString(_m_imageConfig.value(totalKey).toString()).arg(general));
    }
    totalKey = key.arg(S_SKIN_KEY_DEFAULT).arg(S_SKIN_KEY_DEFAULT);
    if (isImageKeyDefined(totalKey)){
        return QFile::exists(QString(_m_imageConfig.value(totalKey).toString()).arg(general).arg(id));
    }
    return false;
}

bool IQSanComponentSkin::isImageKeyDefined(const QString &key) const{
    const QVariant & val = _m_imageConfig[key];
    return val.canConvert<JsonArray>() || JsonUtils::isString(val);
}
