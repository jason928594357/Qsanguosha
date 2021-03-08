#ifndef ENGINE_H
#define ENGINE_H

#include "card.h"
#include "package.h"
#include "general.h"

#include <QObject>
#include <QHash>

class Engine: public QObject
{
    Q_OBJECT
public:
    Engine();
    ~Engine();

    QString translate(const QString &to_translate) const;
    void addPackage(const QString &name);
    void addPackage(Package *package);
    int getCardCount() const;
    const Card *getEngineCard(int cardId) const;
    void playSystemAudioEffect(const QString &name, bool superpose = true) const;
    void playAudioEffect(const QString &filename, bool superpose = true) const;
    inline QList<const General *> getAllGenerals() const {
        return findChildren<const General *>();
    }
private:
    QList<Card *> cards;
    QHash<QString, const General *> generals;
    QHash<QString, QString> translations;
    mutable QMap<QString, const CardPattern *> patterns;
};

extern Engine *Sanguosha;

#endif // ENGINE_H
