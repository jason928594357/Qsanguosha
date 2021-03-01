#include "engine.h"

Engine *Sanguosha = NULL;

Engine::Engine(bool isManualMode){
    Sanguosha = this;
}

int Engine::getCardCount() const{
    return 146;
}
