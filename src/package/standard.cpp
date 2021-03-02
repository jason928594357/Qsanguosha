#include "standard.h"
#include "exppattern.h"

StandardPackage::StandardPackage():Package("standard"){
    patterns["slash"] = new ExpPattern("Slash");
}

QString BasicCard::getType() const {
    return "basic";
}

Card::CardType BasicCard::getTypeId() const {
    return TypeBasic;
}

ADD_PACKAGE(Standard)
