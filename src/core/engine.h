#ifndef ENGINE_H
#define ENGINE_H

#include "general.h"
#include "util.h"

#include <QObject>
#include <QHash>

class AI;
class Scenario;
class LuaBasicCard;
class LuaTrickCard;
class LuaWeapon;
class LuaArmor;
class LuaTreasure;

struct lua_State;

class Engine : public QObject {
    Q_OBJECT
public:
    Engine();
    ~Engine();

    void addTranslationEntry(const char *key, const char *value);
    QString translate(const QString &toTranslate) const;
    QString translate(const QString &toTranslate, const QString &defaultValue) const;

    lua_State *getLuaState() const;
    void addBanPackage(const QString &package_name);

    GeneralList getGeneralList() const;
private:
    QHash<QString, QString> translations;
    GeneralList generalList;
    QSet<QString> ban_package;
    lua_State *lua;
};

static inline QVariant GetConfigFromLuaState(lua_State *L, const char *key) {
    return GetValueFromLuaState(L, "config", key);
}

extern Engine *Sanguosha;
#endif // ENGINE_H
