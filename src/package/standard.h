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
};

class Slash : public BasicCard {
    Q_OBJECT
public:
    Q_INVOKABLE Slash(Card::Suit suit, int number);
};

#endif // STANDARD_H
