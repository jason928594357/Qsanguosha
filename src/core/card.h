#ifndef CARD_H
#define CARD_H

#include <QObject>

class Card :public QObject{
    Q_OBJECT
public:
    enum Suit { Spade, Club, Heart, Diamond, NoSuitBlack, NoSuitRed, NoSuit, SuitToBeDecided = -1 };
    enum HandlingMethod { MethodNone, MethodUse, MethodResponse, MethodDiscard, MethodRecast, MethodPindian };
    Card(Suit suit, int number, bool target_fixed = false);
    Suit getSuit() const;
    int getNumber() const;

protected:
    bool target_fixed;
    bool mute;
    bool will_throw;
    bool has_preact;
    bool can_recast;
    bool transferable;
    Suit m_suit;
    int m_number;
    int m_id;
    Card::HandlingMethod handling_method;
};

#endif // CARD_H
