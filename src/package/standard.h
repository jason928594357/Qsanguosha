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

#endif // STANDARD_H
