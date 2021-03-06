#ifndef STANDARD_H
#define STANDARD_H

#include "package.h"
#include "card.h"

class StandardPackage : public Package
{
    Q_OBJECT
public:
    StandardPackage();
};

// 基本牌
class BasicCard :public Card{
    Q_OBJECT
public:
    BasicCard(Suit suit,int number):Card(suit,number){

    }
    virtual QString getType() const;
    virtual CardType getTypeId() const;
protected:
    QString phase;
    QString target;
    QString effect;
};

// 装备牌
class EquipCard : public Card{
    Q_OBJECT
public:
    EquipCard(Suit suit,int number):Card(suit,number,true){

    }
    virtual QString getType() const;
    virtual CardType getTypeId() const;
};

// 武器牌
class Weapon : public EquipCard {
    Q_OBJECT
public:
    Weapon(Suit suit,int number, int range);
    virtual QString getSubtype() const;
};

// 杀
class Slash : public BasicCard {
    Q_OBJECT
public:
    Q_INVOKABLE Slash(Card::Suit suit, int number);
    virtual QString getSubtype() const;
    virtual QString getDescription() const;
    virtual QString getCardName() const;
    virtual QString getPackageName() const;
};

// 闪
class Jink:public BasicCard{
    Q_OBJECT
public:
    Q_INVOKABLE Jink(Card::Suit suit,int number);
    virtual QString getSubtype() const;
    virtual QString getDescription() const;
    virtual QString getCardName() const;
    virtual QString getPackageName() const;
};

// 桃
class Peach : public BasicCard{
    Q_OBJECT
public:
    Q_INVOKABLE Peach(Card::Suit suit, int number);
    virtual QString getSubtype() const;
    virtual QString getDescription() const;
    virtual QString getCardName() const;
    virtual QString getPackageName() const;
};

#endif // STANDARD_H
