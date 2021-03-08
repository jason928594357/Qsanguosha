#ifndef SKILL_H
#define SKILL_H

#include <QObject>

class Skill: public QObject {
    Q_OBJECT
public:
    Skill(const QString &name);
};

class TriggerSkill : public Skill {
    Q_OBJECT
public:
    TriggerSkill(const QString &name);
};

class MasochismSkill : public TriggerSkill {
    Q_OBJECT
public:
    MasochismSkill(const QString &name);
};

#endif // SKILL_H
