#include "standard.h"
#include "general.h"
#include "skill.h"

class Jianxiong :public MasochismSkill {
public:
    Jianxiong() : MasochismSkill("jianxiong"){

    }
};

void StandardPackage::addGenerals(){
    // 魏
    // 曹操
    General *caocao = new General(this,"caocao","wei");
    caocao->addSkill(new Jianxiong);
}
