#ifndef PACKAGE_H
#define PACKAGE_H

#include "card.h"

#include <QObject>
#include <QMap>
#include <QHash>

class Card;

class CardPattern{

};
class Package : public QObject {
    Q_OBJECT
    Q_ENUMS(Type)
public:
    enum Type{
        GeneralPack,
        CardPack,
        SpecialPack
    };
    Package(const QString &name, Type pack_type = GeneralPack){
        setObjectName(name);
        type = pack_type;
    }
    QMap<QString, const CardPattern *> getPatterns() const
    {
        return patterns;
    }

    template<typename T>
    void addMetaObject(){
        metaobjects << &T::staticMetaObject;
    }
protected:
    QList<const QMetaObject *> metaobjects;
    QMap<QString, const CardPattern *> patterns;
    Type type;
};

typedef QHash<QString, Package *> PackageHash;

class PackageAdder
{
public:
    PackageAdder(const QString &name, Package *pack)
    {
        packages()[name] = pack;
    }

    static PackageHash &packages(void);
};

#define ADD_PACKAGE(name) static PackageAdder name##PackageAdder(#name, new name##Package);

#endif // PACKAGE_H
