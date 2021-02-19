#include "miniscenarios.h"
#include "structs.h"

MiniSceneRule::MiniSceneRule(Scenario *scenario)
    : ScenarioRule(scenario)
{
    events << GameStart << EventPhaseStart << FetchDrawPileCard;
}

void MiniSceneRule::loadSetting(QString path){

}
