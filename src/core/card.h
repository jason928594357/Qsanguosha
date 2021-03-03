#ifndef CARD_H
#define CARD_H

#include <QObject>

class Card : public QObject {
    Q_OBJECT
public:
    enum Suit {
        Spade,//黑桃
        Club,//梅花
        Heart,// 红桃
        Diamond//方片
    };
    enum CardType{
        TypeBasic,
        TypeEquip
    };
    Card(Suit suit, int number, bool target_fixed = false);
    QString getSuitString() const;
    QString getSuitStringTr() const;
    int getId() const;
    virtual void setId(int id);
    static const int S_UNKNOWN_CARD_ID;
    Suit getSuit() const;
    static QString Suit2String(Suit suit);
    static QString Suit2StringTr(Suit suit);
    QString getNumberString() const;
    int getNumber() const;
    virtual QString getType() const = 0;
    virtual QString getSubtype() const = 0;
    virtual QString getPackage() const;
    virtual CardType getTypeId() const = 0;
    virtual QString getName() const;
    virtual QString getDescription() const = 0;
    virtual QString getCardName() const = 0;
    virtual QString getPackageName() const = 0;
protected:

    Suit m_suit;
    int m_number;
    int m_id;
};

#endif // CARD_H
