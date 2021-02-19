#ifndef PACKAGE_H
#define PACKAGE_H

#include <QObject>

class Card;
class Player;
class Skill;

class CardPattern {
public:
    virtual bool match(const Player *player, const Card *card) const = 0;
    virtual bool willThrow() const{
        return true;
    }
    virtual QString getPatternString() const{
        return QString();
    }

    virtual ~CardPattern() {}
};

class Package :public QObject{
    Q_OBJECT
    Q_ENUMS(Type)

public:
    enum Type {
        GeneralPack, CardPack, MixedPack, SpecialPack
    };
    Package(const QString &name, Type pack_type = GeneralPack) {
        setObjectName(name);
        type = pack_type;
    }
    Type getType() const{
        return type;
    }
protected:
    Type type;
};

#endif // PACKAGE_H
