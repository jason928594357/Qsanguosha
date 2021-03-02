#include "standard.h"
#include "exppattern.h"

StandardPackage::StandardPackage():Package("standard"){
    patterns["slash"] = new ExpPattern("Slash");
}

ADD_PACKAGE(Standard)
