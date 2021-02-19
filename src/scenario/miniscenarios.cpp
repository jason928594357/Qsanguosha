#include "miniscenarios.h"

const char *MiniSceneRule::S_EXTRA_OPTION_RANDOM_ROLES = "randomRoles";
const char *MiniSceneRule::S_EXTRA_OPTION_REST_IN_DISCARD_PILE = "restInDiscardPile";

MiniSceneRule::MiniSceneRule(Scenario *scenario)
    : ScenarioRule(scenario)
{
    events << GameStart << EventPhaseStart << FetchDrawPileCard;
}

void MiniSceneRule::loadSetting(QString path){

}
