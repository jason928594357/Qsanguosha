#include "card.h"

const int Card::S_UNKNOWN_CARD_ID = -1;

Card::Card(Suit suit, int number, bool target_fixed)
    :m_suit(suit),m_number(number),m_id(-1){

}

void Card::setId(int id){
    this->m_id = id;
}

int Card::getId() const {
    return m_id;
}
