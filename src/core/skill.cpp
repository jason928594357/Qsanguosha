#include "skill.h"
#include "settings.h"
#include "engine.h"

Skill::Skill(const QString &name, Frequency frequency)
    : frequency(frequency), limit_mark(QString()), relate_to_place(QString()), attached_lord_skill(false)
{

}
TriggerSkill::TriggerSkill(const QString &name)
    : Skill(name), view_as_skill(NULL), global(false), dynamic_priority(0.0)
{
}
ViewAsSkill::ViewAsSkill(const QString &name)
    : Skill(name), response_pattern(QString()), response_or_use(false), expand_pile(QString())
{
}

ScenarioRule::ScenarioRule(Scenario *scenario)
    :TriggerSkill(scenario->objectName())
{
    setParent(scenario);
}
