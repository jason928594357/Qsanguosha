#ifndef EXPPATTERN_H
#define EXPPATTERN_H

#include "package.h"

class ExpPattern:public CardPattern {

public:
    ExpPattern(const QString &exp);
private:
    QString exp;
};

#endif // EXPPATTERN_H
