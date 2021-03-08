#include "standard.h"
#include "exppattern.h"
#include "engine.h"

StandardPackage::StandardPackage():Package("standard"){
    addGenerals();
    patterns["slash"] = new ExpPattern("Slash");
}

QString BasicCard::getType() const {
    return tr("basic card");
}

Card::CardType BasicCard::getTypeId() const {
    return TypeBasic;
}

QString EquipCard::getType() const {
    return tr("equip");
}

Card::CardType EquipCard::getTypeId() const {
    return TypeEquip;
}

Weapon::Weapon(Suit suit,int number,int range)
    :EquipCard(suit,number)
{
}

QString Weapon::getSubtype()const {
    return tr("weapon card");
}

ADD_PACKAGE(Standard)
