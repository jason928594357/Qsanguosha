#ifndef ENGINE_H
#define ENGINE_H

#include "general.h"

#include <QObject>
#include <QHash>

class Engine : public QObject {
    Q_OBJECT
public:
    Engine();
    ~Engine();

    void addTranslationEntry(const char *key, const char *value);
    QString translate(const QString &toTranslate, const QString &defaultValue) const;
    QString translate(const QString &toTranslate) const;
    GeneralList getGeneralList() const;
private:
    QHash<QString, QString> translations;
    GeneralList generalList;
};

extern Engine *Sanguosha;
#endif // ENGINE_H
