#include "standard.h"
#include "standardequips.h"
#include "package.h"

Slash::Slash(Card::Suit suit, int number):BasicCard(suit,number){
    setObjectName("slash");
}

QString Slash::getSubtype() const
{
    return "attack card";
}

StandardCardPackage::StandardCardPackage()
    : Package("standard card", Package::CardPack){
    QList<Card *> cards;
    cards << new Slash(Card::Spade,7)
          <<new Slash(Card::Spade,8);
    foreach (Card *card, cards) {
        card->setParent(this);
    }
}

ADD_PACKAGE(StandardCard)
