#ifndef NAMESPACE_H
#define NAMESPACE_H

#include <QString>

namespace HegemonyMode {
    QString GetMappedRole(const QString &kingdom);
    QString GetMappedKingdom(const QString &role);

    enum ArrayType {
        Siege,
        Formation
    };
}

namespace MaxCardsType {
    enum MaxCardsCount {
        Max = 1,
        Normal = 0,
        Min = -1,
    };
}

#endif // NAMESPACE_H
