#ifndef MINISCENERULE_H
#define MINISCENERULE_H

#include "scenario.h"
#include "skill.h"

class MiniSceneRule :public ScenarioRule {
    Q_OBJECT
public:
    static const char *S_EXTRA_OPTION_RANDOM_ROLES;
    static const char *S_EXTRA_OPTION_REST_IN_DISCARD_PILE;
    MiniSceneRule(Scenario *scenario);
    void loadSetting(QString path);
};

#endif // MINISCENERULE_H
