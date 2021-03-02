#ifndef CARD_H
#define CARD_H

#include <QObject>

class Card : public QObject {
    Q_OBJECT
public:
    enum Suit {
        Spade
    };
    enum CardType{
        TypeBasic
    };
    Card(Suit suit, int number, bool target_fixed = false);
    QString getSuitString() const;
    int getId() const;
    virtual void setId(int id);
    static const int S_UNKNOWN_CARD_ID;
    Suit getSuit() const;
    static QString Suit2String(Suit suit);
    QString getNumberString() const;
    int getNumber() const;
    virtual QString getType() const = 0;
    virtual QString getSubtype() const = 0;
    virtual QString getPackage() const;
    virtual CardType getTypeId() const = 0;
protected:

    Suit m_suit;
    int m_number;
    int m_id;
};

#endif // CARD_H
