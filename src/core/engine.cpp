#include "engine.h"
#include "audio.h"
#include "settings.h"

Engine *Sanguosha = NULL;

Engine::Engine(){
    Sanguosha = this;
}

Engine::~Engine(){
    Audio::quit();
}

int Engine::getCardCount() const{
    return 146;
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
