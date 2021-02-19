#include "general.h"
#include "skinbank.h"
#include "package.h"

General::General(Package *package, const QString &name, const QString &kingdom,
    int double_max_hp, bool male, bool hidden, bool never_shown)
    : QObject(package), kingdom(kingdom),
      double_max_hp(double_max_hp), gender(male ? Male : Female),
      hidden(hidden), never_shown(never_shown),
      head_max_hp_adjusted_value(0), deputy_max_hp_adjusted_value(0),
      skin_count(-1){
    static QChar lord_symbol('$');
    if(name.endsWith(lord_symbol)){
        QString copy = name;
        copy.remove(lord_symbol);
        lord = true;
        setObjectName(copy);
    }else{
        lord = false;
        setObjectName(name);
    }
}

bool General::isTotallyHidden() const{
    return never_shown;
}

int General::skinCount() const{
    if(skin_count!=-1){
        return skin_count;
    }
    forever {
        if(!G_ROOM_SKIN.generalHasSkin(objectName(),(++skin_count)+1)){
            return skin_count;
        }
    }
}
