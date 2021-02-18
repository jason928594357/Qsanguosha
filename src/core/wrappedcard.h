#ifndef WRAPPEDCARD_H
#define WRAPPEDCARD_H

#include "card.h"

class WrappedCard :public Card {
    Q_OBJECT
public:
    Q_INVOKABLE WrappedCard(Card *card);
protected:
    Card *m_card;
    mutable bool m_isModified;
};

#endif // WRAPPEDCARD_H
