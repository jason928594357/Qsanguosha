#ifndef ROOMSTATE_H
#define ROOMSTATE_H

#include "wrappedcard.h"

#include <QHash>

class RoomState {

public:
    inline RoomState(bool isClient) {
        m_isClient = isClient;
    }
    ~RoomState();
protected:
    QHash<int, WrappedCard *> m_cards;
    bool m_isClient;
};

#endif // ROOMSTATE_H
