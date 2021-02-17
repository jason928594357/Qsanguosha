#include "engine.h"

Engine *Sanguosha = NULL;

void Engine::addTranslationEntry(const char *key, const char *value) {
    translations.insert(key, QString::fromUtf8(value));
}

Engine::Engine(){
    Sanguosha = this;
}

QString Engine::translate(const QString &toTranslate) const{
    QStringList list = toTranslate.split("\\");
    QString res;
    foreach (const QString &str, list) {
        res.append(translations.value(str,str));
    }
    return res;
}
GeneralList Engine::getGeneralList() const{
     return generalList;
}

lua_State *Engine::getLuaState() const{
    return lua;
}

Engine::~Engine(){

}
