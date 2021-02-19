#include "customassigndialog.h"
#include "scenario.h"
#include "engine.h"
#include "miniscenarios.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

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
    if(m_starter.isEmpty()){
        QMessageBox::warning(NULL,tr("Warning"),tr("There is not a starter"));
        return false;
    }
    QString line;
    m_settedOptions << m_randomRolesBox->isChecked() << m_restInDpBox->isChecked();
    foreach (bool option, m_settedOptions) {
        if(option){
            line.append("extraOptions:");
            break;
        }
    }
    if (m_randomRolesBox->isChecked()) {
        line.append(MiniSceneRule::S_EXTRA_OPTION_RANDOM_ROLES);
        line.append(" ");
    }
    if (m_restInDpBox->isChecked()) {
        line.append(MiniSceneRule::S_EXTRA_OPTION_REST_IN_DISCARD_PILE);
        line.append(" ");
    }
    line.remove(line.length() - 1, 1);
    line.append("\n");

    if(m_settedPile.length()){
        line.append("setPile:");
        for (int i = m_settedPile.length() - 1; i >= 0; i--) {
            int id = m_settedPile.at(i);
            line.append(QString::number(id));
            line.append(",");
        }
        line.remove(line.length() - 1, 1);
        line.append("\n");
    }
    for(int i=0;i<m_list->count();i++){
        QString name = (i == 0) ? "Player" : QString("AI%1").arg(QString::number(i));

        if(m_canChooseGeneralFreely[name] || m_generalMap[name].isEmpty()){
            line.append("general:select ");
        }else {
            line.append(QString("general:%1 ").arg(m_generalMap[name]));
        }

        if (m_canChooseGeneral2Freely[name] || m_generalMap2[name].isEmpty()){
            line.append("general2:select ");
        }else if (!m_generalMap2[name].isEmpty()){
            line.append(QString("general2:%1 ").arg(m_generalMap2[name]));
        } if (m_starter == name) line.append("starter:true ");
        if (!m_playersMarks[name].isEmpty()) {
            line.append("marks:");
            QMap<QString, int> marks = m_playersMarks[name];
            foreach (const QString &mark_name, marks.keys()) {
                if (marks.value(mark_name) > 0)
                    line.append(QString("%1*%2,").arg(mark_name).arg(QString::number(marks.value(mark_name))));
            }

            if (line.endsWith("marks:"))
                line.remove(line.length() - 7, 6);
            else {
                line.remove(line.length() - 1, 1);
                line.append(" ");
            }
        }
        if (m_playersMaxHp[name] > 0) line.append(QString("maxhp:%1 ").arg(m_playersMaxHp[name]));
        if (m_playersHp[name] > 0) line.append(QString("hp:%1 ").arg(m_playersHp[name]));
        if (m_playerIsTurned[name]) line.append("turned:true ");
        if (m_playerIsChained[name]) line.append("chained:true ");
        if (m_playerHasShownHead[name]) line.append("shown_head:true ");
        if (m_playerHasShownDeputy[name]) line.append("shown_deputy:true ");
        if (m_settedNationality[name]) line.append(QString("nationality:%1 ").arg(m_assignedNationality[name]));
        if (m_playersExtraSkills[name].length() > 0) {
            line.append("acquireSkills:");
            foreach (const QString &skill_name, m_playersExtraSkills[name]) {
                line.append(skill_name + ",");
            }
            line.remove(line.length() - 1, 1);
            line.append(" ");
        }
        if (i == 0) {
            if (m_isEndedByPile) {
                QString winner = m_endedByPileBox->itemData(m_endedByPileBox->currentIndex()).toString();
                line.append(QString("endedByPile:%1 ").arg(winner));
            }
            if (m_isSingleTurn) {
                QString winner = m_singleTurnBox->itemData(m_singleTurnBox->currentIndex()).toString();
                line.append(QString("singleTurn:%1 ").arg(winner));
            }
            else if (m_isBeforeNext) {
                QString winner = m_beforeNextBox->itemData(m_beforeNextBox->currentIndex()).toString();
                line.append(QString("beforeNext:%1 ").arg(winner));
            }
        }
        if (m_playerDrawNumWhenStarts.contains(name) && m_playerDrawNumWhenStarts[name] != 4)
            line.append(QString("draw:%1 ").arg(m_playerDrawNumWhenStarts[name]));

        if (m_playersEquips[name].length()) {
            line.append("equip:");
            foreach (int equip, m_playersEquips[name]) line.append(QString("%1,").arg(equip));
            line.chop(1);
            line.append(" ");
        }

        if (m_playersHandcards[name].length()) {
            line.append("hand:");
            foreach (int hand, m_playersHandcards[name]) line.append(QString("%1,").arg(hand));
            line.chop(1);
            line.append(" ");
        }

        if (m_playersJudges[name].length()) {
            line.append("judge:");
            foreach (int judge, m_playersJudges[name]) line.append(QString("%1,").arg(judge));
            line.chop(1);
            line.append(" ");
        }

        line.append("\n");
    }

    QString filename = path;
    if (path.size() < 1)
        filename = QFileDialog::getSaveFileName(this,
                                                tr("Save mini scenario settings"),
                                                "etc/customScenes/",
                                                tr("Pure text replay file (*.txt)"));

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;


    QTextStream out(&file);
    out << line;
    file.close();

    return true;
}
