#ifndef GENERAL_H
#define GENERAL_H

class Package;

#include <QObject>

class General :public QObject{
    Q_OBJECT
public:
    explicit General(Package *package, const QString &name, const QString &kingdom,
            int double_max_hp = 4, bool male = true, bool hidden = false, bool never_shown = false);
    bool isTotallyHidden() const;
    enum Gender {
        Sexless,
        Male,
        Female,
        Neuter
    };
    int skinCount() const;

private:
    QString kingdom;
    int double_max_hp;
    Gender gender;
    bool lord;
    bool hidden;
    bool never_shown;
    int head_max_hp_adjusted_value;
    int deputy_max_hp_adjusted_value;
    mutable int skin_count;
};

Q_DECLARE_METATYPE(const General *)

typedef QList<const General *> GeneralList;

#endif // GENERAL_H
