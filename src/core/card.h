#ifndef CARD_H
#define CARD_H

#include <QObject>

class Card : public QObject {
    Q_OBJECT
public:
    enum Suit {
        Spade
    };
    Card(Suit suit, int number, bool target_fixed = false);
    int getId() const;
    virtual void setId(int id);
    static const int S_UNKNOWN_CARD_ID;
protected:

    Suit m_suit;
    int m_number;
    int m_id;
};

#endif // CARD_H
