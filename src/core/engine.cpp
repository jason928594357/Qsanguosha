#include "engine.h"

Engine *Sanguosha = NULL;

void Engine::addTranslationEntry(const char *key, const char *value) {
    translations.insert(key, QString::fromUtf8(value));
}

Engine::Engine(){
    Sanguosha = this;
}

void Engine::addBanPackage(const QString &package_name) {
    ban_package.insert(package_name);
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

QMap<QString, QString> Engine::getAvailableModes() const{
    return modes;
}


QList<const Package *> Engine::getPackages() const{
    return packages;
}


const Scenario *Engine::getScenario(const QString &name) const{
    if(m_scenarios.contains(name)){
        return m_scenarios[name];
    } else if(m_miniScenes.contains(name)){
        return m_miniScenes[name];
    } else if(name == "custom_scenario"){
        return m_customScene;
    }else {
        return NULL;
    }
}
