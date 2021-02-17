#ifndef GENERAL_H
#define GENERAL_H

#include <QObject>

class General :public QObject{
    Q_OBJECT
public:
    General();
    bool isTotallyHidden() const;


private:
    bool never_shown;
};

Q_DECLARE_METATYPE(const General *)

typedef QList<const General *> GeneralList;

#endif // GENERAL_H
