#include "scenario.h"

Scenario::Scenario(const QString &name)
    : Package(name, Package::SpecialPack), rule(NULL), random_seat(true)
{
}

ScenarioRule *Scenario::getRule() const{
    return rule;
}
