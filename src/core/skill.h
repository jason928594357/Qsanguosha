#ifndef SKILL_H
#define SKILL_H

#include "structs.h"

#include <QObject>

class Skill: public QObject{
    Q_OBJECT
    Q_ENUMS(Frequency)

public:
    enum Frequency {
        Frequent,
        NotFrequent,
        Compulsory,
        Limited,
        Wake
    };
    explicit Skill(const QString &name, Frequency frequent = NotFrequent);
protected:
    Frequency frequency;
    QString limit_mark;
    QString relate_to_place;
    bool attached_lord_skill;
};

class ViewAsSkill: public Skill{
    Q_OBJECT
public:
    ViewAsSkill(const QString &name);
protected:
    QString response_pattern;
    bool response_or_use;
    QString expand_pile;
};

class TriggerSkill : public Skill{
    Q_OBJECT
public:
    TriggerSkill(const QString &name);
protected:
    const ViewAsSkill *view_as_skill;
    QList<TriggerEvent> events;
    bool global;
private:
    mutable double dynamic_priority;
};

class Scenario;

class ScenarioRule : public TriggerSkill{
    Q_OBJECT
public:
    ScenarioRule(Scenario *scenario);
};

#endif // SKILL_H
