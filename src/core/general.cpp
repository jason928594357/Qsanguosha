#include "general.h"

General::General(Package *package, const QString &name, const QString &kingdom, int max_hp, bool male)
    : QObject(package),kingdom(kingdom),max_hp(max_hp),gender(male?Male:Female)
{

}

void General::addSkill(Skill *skill){

}
