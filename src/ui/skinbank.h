#ifndef SKINBANK_H
#define SKINBANK_H

#include "json.h"

#include <QString>

class IQSanComponentSkin{
public:
    bool load(const QString &layoutConfigFileName, const QString &imageConfigFileName,
              const QString &audioConfigFileName, const QString &animationConfigFileName);
    QStringList getAudioFileNames(const QString &key) const;
    QString getRandomAudioFileName(const QString &key) const;

protected:
    JsonObject _m_audioConfig;
};

class QSanRoomSkin:public IQSanComponentSkin{
public:
    QString getPlayerAudioEffectPath(const QString &eventName, bool isMale, int index = -1) const;
    QString getPlayerAudioEffectPath(const QString &eventName, const QString &category, int index = -1) const;

    static const char *S_SKIN_KEY_PLAYER_AUDIO_EFFECT;
};

class QSanSkinScheme{
public:
    bool load(const QVariant &configs);
    const QSanRoomSkin &getRoomSkin() const;
protected:
    QSanRoomSkin _m_roomSkin;
};

class QSanSkinFactory
{
public:
    static QSanSkinFactory &getInstance();
    bool switchSkin(QString skinName);
    const QSanSkinScheme &getCurrentSkinScheme();
    QString S_DEFAULT_SKIN_NAME;
    QString S_COMPACT_SKIN_NAME;
protected:
    QSanSkinFactory(const char *fileName);
    static QSanSkinFactory* _sm_singleton;
    QSanSkinScheme _sm_currentSkin;
    JsonObject _m_skinList;
    QString _m_skinName;
};

#define G_ROOM_SKIN (QSanSkinFactory::getInstance().getCurrentSkinScheme().getRoomSkin())

#endif // SKINBANK_H
