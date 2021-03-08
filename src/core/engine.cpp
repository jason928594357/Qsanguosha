#include "engine.h"
#include "audio.h"
#include "settings.h"

Engine *Sanguosha = NULL;

Engine::Engine(){
    Sanguosha = this;
    QStringList package_names = QStringList()<<"StandardCard"<<"Standard";
    foreach (QString name, package_names) {
        addPackage(name);
    }
}

void Engine::addPackage(const QString &name){
    Package *pack = PackageAdder::packages()[name];
    if(pack){
        addPackage(pack);
    }else{
        qWarning("Package %s cannot be loaded!",qPrintable(name));
    }
}

void Engine::addPackage(Package *package){
    if(findChild<const Package *>(package->objectName())){
        return;
    }
    package->setParent(this);
    patterns.unite(package->getPatterns());
    QList<Card *> all_cards = package->findChildren<Card *>();
    foreach(Card *card, all_cards){
        card->setId(cards.length());
        cards << card;
    }

    QList<General *> all_generals = package->findChildren<General *>();

    foreach(General *general,all_generals){
        generals.insert(general->objectName(),general);
    }
}

Engine::~Engine(){
    Audio::quit();
}

int Engine::getCardCount() const{
    return cards.length();
}

void Engine::playSystemAudioEffect(const QString &name, bool superpose) const{
    playAudioEffect(QString("audio/system/%1.ogg").arg(name), superpose);
}

void Engine::playAudioEffect(const QString &filename, bool superpose) const{
#ifdef AUDIO_SUPPORT
    if (!Config.EnableEffects){
        return;
    }
    if (filename.isNull()){
        return;
    }
    Audio::play(filename, superpose);
#endif
}

const Card *Engine::getEngineCard(int cardId) const{
    if(cardId == Card::S_UNKNOWN_CARD_ID){
        return NULL;
    }else if (cardId < 0 || cardId >= cards.length()){
        Q_ASSERT(!(cardId<0 || cardId >= cards.length()));
        return NULL;
    }else{
        Q_ASSERT(cards[cardId] != NULL);
        return cards[cardId];
    }
}

QString Engine::translate(const QString &to_translate) const{
    QStringList list = to_translate.split("\\");
    QString res;
    foreach (QString str, list) {
        res.append(translations.value(str, str));
    }
    return res;
}
