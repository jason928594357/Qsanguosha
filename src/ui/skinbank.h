#ifndef IQSANCOMPONENTSKIN_H
#define IQSANCOMPONENTSKIN_H

#include <QPixmap>

class IQSanComponentSkin {
public:
    class QSanSimpleTextFont {

    };
};

class QSanRoomSkin : public IQSanComponentSkin{
public:
    enum GeneralIconSize{
        S_GENERAL_ICON_SIZE_LARGE
    };
    QPixmap getGeneralPixmap(const QString &generalName, GeneralIconSize size, const int skinId = 0) const;
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
    QSanSkinScheme _sm_currentSkin;
};
#define G_ROOM_SKIN (QSanSkinFactory::getInstance().getCurrentSkinScheme().getRoomSkin())

#endif // IQSANCOMPONENTSKIN_H
