#include "skill.h"

Skill::Skill(const QString &name)
{

}

TriggerSkill::TriggerSkill(const QString &name)
    :Skill(name)
{

}

MasochismSkill::MasochismSkill(const QString &name)
    :TriggerSkill(name)
{

}
