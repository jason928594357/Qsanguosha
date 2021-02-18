#include "wrappedcard.h"

WrappedCard::WrappedCard(Card *card)
    : Card(card->getSuit(), card->getNumber()), m_card(NULL), m_isModified(false)
{

}

int Card::getNumber() const{

}

Card::Suit Card::getSuit() const{

}
