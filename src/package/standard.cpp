#include "standard.h"
#include "exppattern.h"
#include "engine.h"

StandardPackage::StandardPackage():Package("standard"){
    patterns["slash"] = new ExpPattern("Slash");
}

QString BasicCard::getType() const {
    return tr("basic card");
}

Card::CardType BasicCard::getTypeId() const {
    return TypeBasic;
}

ADD_PACKAGE(Standard)
