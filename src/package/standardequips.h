#ifndef STANDARDEQUIPS_H
#define STANDARDEQUIPS_H

#include "standard.h"

//  诸葛连弩
class Crossbow : public Weapon {
    Q_OBJECT
public:
    Q_INVOKABLE Crossbow(Card::Suit suit);
    virtual QString getDescription() const;
    virtual QString getCardName() const;
    virtual QString getPackageName() const;
};

class StandardCardPackage : public Package
{
    Q_OBJECT
public:
    StandardCardPackage();
};

#endif // STANDARDEQUIPS_H
