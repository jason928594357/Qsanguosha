#ifndef UTIL_H
#define UTIL_H

struct lua_State;
class QVariant;

#include <QList>
#include <QStringList>
#include <QVariant>

template<typename T>
void qShuffle(QList<T> &list){
    int n =list.length();
    for(int i=0;i<n;i++){
        int r= qrand() % (n-i)+i;
        list.swap(i,r);
    }
}

QVariant GetValueFromLuaState(lua_State *L, const char *table_name, const char *key);

QStringList IntList2StringList(const QList<int> &intlist);
QList<int> StringList2IntList(const QStringList &stringlist);
QVariantList IntList2VariantList(const QList<int> &intlist);
QList<int> VariantList2IntList(const QVariantList &variantlist);

bool isNormalGameMode(const QString &mode);

static const int S_EQUIP_AREA_LENGTH = 5;

#endif // UTIL_H
