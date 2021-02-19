#ifndef SCENARIO_H
#define SCENARIO_H

#include "package.h"


class Room;
class ScenarioRule;

class Scenario : public Package {
    Q_OBJECT
public:
    explicit Scenario(const QString &name);

    ScenarioRule *getRule() const;

protected:
    ScenarioRule *rule;
    bool random_seat;
};

#endif // SCENARIO_H
