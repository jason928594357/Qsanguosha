#ifndef GENERAL_H
#define GENERAL_H

#include "package.h"
#include "skill.h"

#include <QObject>

class General : public QObject {
    Q_OBJECT
public:
    explicit General(Package *package, const QString &name, const QString &kingdom,
                     int max_hp = 4,bool male = true);
    enum Gender {
        Male,//男
        Female//女
    };
    void addSkill(Skill *skill);
private:
    QString kingdom;
    int max_hp;
    Gender gender;
};

#endif // GENERAL_H
