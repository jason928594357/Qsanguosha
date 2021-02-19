#ifndef CUSTOMASSIGNDIALOG_H
#define CUSTOMASSIGNDIALOG_H

#include "flatdialog.h"

class CustomAssignDialog : public FlatDialog {
    Q_OBJECT
public:
    CustomAssignDialog(QWidget *parent);

protected:
    virtual void accept();
    virtual void reject();

private:
    bool m_enableGeneral2;
    bool m_isEndedByPile;
    bool m_isSingleTurn;
    bool m_isBeforeNext;

private slots:
    bool save(const QString &path);
    bool save();

signals:
    void scenario_changed();
};

#endif // CUSTOMASSIGNDIALOG_H
