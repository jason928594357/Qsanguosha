#include "customassigndialog.h"
#include "scenario.h"
#include "engine.h"
#include "miniscenerule.h"

CustomAssignDialog *CustomInstance = NULL;

CustomAssignDialog::CustomAssignDialog(QWidget *parent)
    :FlatDialog(parent),m_enableGeneral2(false),
      m_isEndedByPile(false), m_isSingleTurn(false), m_isBeforeNext(false)
{

}

void CustomAssignDialog::accept(){
    if(save("etc/customScenes/custom_scenario.txt")){
        const Scenario *scene = Sanguosha->getScenario("custom_scenario");
        MiniSceneRule *rule = qobject_cast<MiniSceneRule *>(scene->getRule());
        Q_ASSERT(rule != NULL);
        rule->loadSetting("etc/customScenes/custom_scenario.txt");
        emit scenario_changed();
        QDialog::accept();
    }
}

void CustomAssignDialog::reject() {
    QDialog::reject();
}

bool CustomAssignDialog::save() {
    return save(QString());
}

bool CustomAssignDialog::save(const QString &path){
    return true;
}
