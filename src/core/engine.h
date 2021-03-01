#ifndef ENGINE_H
#define ENGINE_H

#include "card.h"

#include <QObject>

class Engine: public QObject
{
    Q_OBJECT
public:
    Engine();
    ~Engine();

	int getCardCount() const;
    void playSystemAudioEffect(const QString &name, bool superpose = true) const;
    void playAudioEffect(const QString &filename, bool superpose = true) const;
	private:
	QList<Card *> cards;
};

extern Engine *Sanguosha;

#endif // ENGINE_H
