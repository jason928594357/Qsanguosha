#include "card.h"

const int Card::S_UNKNOWN_CARD_ID = -1;

Card::Card(Suit suit, int number, bool target_fixed)
    :m_suit(suit),m_number(number),m_id(-1){

}

QString Card::getSuitString() const {
    return Suit2String(getSuit());
}

void Card::setId(int id){
    this->m_id = id;
}

int Card::getId() const {
    return m_id;
}

Card::Suit Card::getSuit() const {
    return m_suit;
}

QString Card::Suit2String(Suit suit){
    switch (suit) {
    case Spade:
        return "spade";
    default:
        return "no_suit";
    }
}

int Card::getNumber() const {
    return m_number;
}

QString Card::getNumberString() const {
    int number = getNumber();
    if(number == 10){
        return "10";
    } else {
        static const char *number_string = "-A23456789-JQK";
        return QString(number_string[number]);
    }
}

QString Card::getPackage() const {
    if(parent()){
        return parent()->objectName();
    }else {
        return QString();
    }
}
