#ifndef MINISCENERULE_H
#define MINISCENERULE_H

#include "scenario.h"
#include "skill.h"

class MiniSceneRule :public ScenarioRule {
    Q_OBJECT
public:
    MiniSceneRule(Scenario *scenario);
    void loadSetting(QString path);
};

#endif // MINISCENERULE_H
