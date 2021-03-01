#ifndef ENGINE_H
#define ENGINE_H

#include "card.h"

#include <QObject>

class Engine:public QObject {
    Q_OBJECT
public:
    Engine(bool isManualMode = false);
    int getCardCount() const;
private:
    QList<Card *> cards;
};

extern Engine *Sanguosha;

#endif // ENGINE_H
