#include "skinbank.h"
#include "settings.h"
#include "json.h"

#include <QMessageBox>

using namespace JsonUtils;

const char *QSanRoomSkin::S_SKIN_KEY_PLAYER_AUDIO_EFFECT = "playerAudioEffect-%1-%2";

QSanSkinFactory *QSanSkinFactory::_sm_singleton = NULL;

bool IQSanComponentSkin::load(const QString &layoutConfigFileName, const QString &imageConfigFileName, const QString &audioConfigFileName, const QString &animationConfigFileName){
    bool success = true;
    QString errorMsg;
    if(!audioConfigFileName.isNull()){
        JsonDocument audioDoc = JsonDocument::fromFilePath(audioConfigFileName);
        if(!audioDoc.isValid() || !audioDoc.isObject()){
            errorMsg = QString("Error when reading audio config file \"%1\": \n%2").arg(audioConfigFileName).arg(audioDoc.errorString());
            QMessageBox::warning(NULL,"Config Error",errorMsg);
            success = false;
        }
        _m_audioConfig = audioDoc.object();
    }
    return success;
}

bool QSanSkinScheme::load(const QVariant &configs){
    JsonObject config = configs.value<JsonObject>();
    if(config.isEmpty()){
        return false;
    }
    QString layoutFile = config["roomLayoutConfigFile"].toString();
    QString imageFile = config["roomImageConfigFile"].toString();
    QString audioFile = config["roomAudioConfigFile"].toString();
    QString animFile = config["roomAnimationConfigFile"].toString();
    return _m_roomSkin.load(layoutFile,imageFile,audioFile,animFile);
}

QSanSkinFactory &QSanSkinFactory::getInstance(){
    if(_sm_singleton == NULL){
        _sm_singleton = new QSanSkinFactory("skins/skinList.json");
    }
    return *_sm_singleton;
}

QSanSkinFactory::QSanSkinFactory(const char *fileName){
    bool use_full = Config.value("useFullSkin",true).toBool();
    QString suf = use_full ? "full" : QString();
    S_DEFAULT_SKIN_NAME = suf + "default";
    S_COMPACT_SKIN_NAME = suf + "compact";
    JsonDocument doc = JsonDocument::fromFilePath(fileName);
    _m_skinList = doc.object();
    _m_skinName = "";
    switchSkin(S_DEFAULT_SKIN_NAME);
}

bool QSanSkinFactory::switchSkin(QString skinName){
    if(skinName == _m_skinName){
        return false;
    }
    bool success = false;
    if(_m_skinName!=S_DEFAULT_SKIN_NAME){
        success = _sm_currentSkin.load(_m_skinList[S_DEFAULT_SKIN_NAME.toLatin1().constData()]);
        if(!success){
            qWarning("Cannot load default skin!");
        }
    }
    if(skinName != S_DEFAULT_SKIN_NAME){
        success = _sm_currentSkin.load(_m_skinList[skinName.toLatin1().constData()]);
    }
    if(!success){
        qWarning("Loading skin %s failed",skinName.toLatin1().constData());
    }
    _m_skinName = skinName;
    return success;
}

const QSanSkinScheme &QSanSkinFactory::getCurrentSkinScheme(){
    return this->_sm_currentSkin;
}

const QSanRoomSkin &QSanSkinScheme::getRoomSkin() const{
    return _m_roomSkin;
}

QString QSanRoomSkin::getPlayerAudioEffectPath(const QString &eventName, const QString &category, int index) const{
    QString fileName;
    QString key = QString(QSanRoomSkin::S_SKIN_KEY_PLAYER_AUDIO_EFFECT).arg(category).arg(eventName);
    if (index < 0){
        fileName = getRandomAudioFileName(key);
    } else {
        QStringList fileNames = getAudioFileNames(key);
        if(!fileNames.isEmpty()){
            if(fileNames.length() >= index){
                return fileNames[index-1];
            } else {
                while(index > fileNames.length()){
                    index -= fileNames.length();
                }
                return fileNames[index-1];
            }
        }
    }
    return fileName;
}

QString IQSanComponentSkin::getRandomAudioFileName(const QString &key) const{
    QStringList audios = getAudioFileNames(key);
    if(audios.isEmpty()){
        return QString();
    }
    int r = qrand() % audios.length();
    return audios[r];
}

QStringList IQSanComponentSkin::getAudioFileNames(const QString &key) const{
    const QVariant &result = _m_audioConfig[key];
    if(result.isNull()){
        return QStringList();
    }else if (JsonUtils::isString(result)){
        return QStringList(result.toString());
    }else if (result.canConvert<JsonArray>()){
        QStringList audios;
        tryParse(result, audios);
        return audios;
    }
    return QStringList();
}

QString QSanRoomSkin::getPlayerAudioEffectPath(const QString &eventName, bool isMale, int index) const{
    return getPlayerAudioEffectPath(eventName,QString(isMale?"male":"female"),index);
}


