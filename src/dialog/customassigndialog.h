#ifndef CUSTOMASSIGNDIALOG_H
#define CUSTOMASSIGNDIALOG_H

#include "flatdialog.h"

#include <QListWidget>
#include <QCheckBox>
#include <QComboBox>

class CustomAssignDialog : public FlatDialog {
    Q_OBJECT
public:
    CustomAssignDialog(QWidget *parent);

protected:
    virtual void accept();
    virtual void reject();

private:
    QListWidget *m_list;
    bool m_enableGeneral2;
    bool m_isEndedByPile;
    bool m_isSingleTurn;
    bool m_isBeforeNext;
    QString m_starter;
    QList<bool> m_settedOptions;
    QCheckBox *m_randomRolesBox;
    QCheckBox *m_restInDpBox;
    QList<int> m_settedPile;
    QMap<QString, bool> m_canChooseGeneralFreely;
    QMap<QString, int> m_playersMaxHp;
    QMap<QString, int> m_playersHp;
    QMap<QString, bool> m_playerIsTurned;
    QMap<QString, bool> m_playerIsChained;
    QMap<QString, bool> m_playerHasShownHead;
    QMap<QString, bool> m_playerHasShownDeputy;
    QMap<QString, QString> m_generalMap;
    QMap<QString, QString> m_generalMap2;
    QMap<QString, bool> m_canChooseGeneral2Freely;
    QMap<QString, QMap<QString, int> > m_playersMarks;
    QMap<QString, bool> m_settedNationality;
    QMap<QString, QString> m_assignedNationality;
    QMap<QString, QStringList> m_playersExtraSkills;
    QComboBox *m_endedByPileBox;
    QComboBox *m_singleTurnBox;
    QComboBox *m_beforeNextBox;
    QMap<QString, int> m_playerDrawNumWhenStarts;
    QMap<QString, QList<int> > m_playersEquips;
    QMap<QString, QList<int> > m_playersHandcards;
    QMap<QString, QList<int> > m_playersJudges;
private slots:
    bool save(const QString &path);
    bool save();

signals:
    void scenario_changed();
};

#endif // CUSTOMASSIGNDIALOG_H
