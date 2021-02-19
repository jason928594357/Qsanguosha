#ifndef IQSANCOMPONENTSKIN_H
#define IQSANCOMPONENTSKIN_H

#include "json.h"

#include <QPixmap>

class IQSanComponentSkin {
public:
    class QSanSimpleTextFont {

    };
    static const char *S_SKIN_KEY_DEFAULT;
    bool isImageKeyDefined(const QString &key) const;
protected:
    JsonObject _m_imageConfig;
};

class QSanRoomSkin : public IQSanComponentSkin{
public:
    enum GeneralIconSize{
        S_GENERAL_ICON_SIZE_LARGE,
        S_GENERAL_ICON_SIZE_HERO_SKIN
    };
    bool generalHasSkin(const QString &general, const int skinId = 1, const bool isCard = false) const;

    QPixmap getGeneralPixmap(const QString &generalName, GeneralIconSize size, const int skinId = 0) const;
    static const char *S_SKIN_KEY_GENERAL_CARD;
    static const char *S_SKIN_KEY_PLAYER_GENERAL_ICON;
protected:


};

class QSanSkinScheme {
public:
    bool load(const QVariant &configs);
    const QSanRoomSkin& getRoomSkin() const;
    protected:
    QSanRoomSkin _m_roomSkin;
};

class QSanSkinFactory{
public:
    static QSanSkinFactory &getInstance();
    const QSanSkinScheme &getCurrentSkinScheme();

protected:
    QSanSkinFactory(const char *fileName);
    static QSanSkinFactory* _sm_singleton;
    QSanSkinScheme _sm_currentSkin;
};
#define G_ROOM_SKIN (QSanSkinFactory::getInstance().getCurrentSkinScheme().getRoomSkin())

#endif // IQSANCOMPONENTSKIN_H
