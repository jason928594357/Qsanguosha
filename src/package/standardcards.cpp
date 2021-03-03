#include "standard.h"
#include "standardequips.h"
#include "package.h"

Slash::Slash(Card::Suit suit, int number):BasicCard(suit,number){
    setObjectName("slash");
    phase = "play phase";
}

QString Slash::getSubtype() const
{
    return tr("attack card");
}
QString Slash::getDescription() const{
    QString description = tr("<b>【Slash】</b>Basic card<br /><b>Phase</b>:play phase<br /><b>Target</b>:attack the other role wihtin range of the attack<br /><b>Effect</b>:a point damage to the target role.");
    return description;
}

QString Slash::getCardName() const {
    return tr("slash");
}

QString Slash::getPackageName() const {
    return tr("standard card");
}

StandardCardPackage::StandardCardPackage()
    : Package("standard card", Package::CardPack){
    QList<Card *> cards;
    cards << new Slash(Card::Spade,7)
          <<new Slash(Card::Spade,8)
         << new Slash(Card::Spade, 8)
         << new Slash(Card::Spade, 9)
         << new Slash(Card::Spade, 9)
         << new Slash(Card::Spade, 10)
         << new Slash(Card::Spade, 10)
         << new Slash(Card::Club, 2)
         << new Slash(Card::Club, 3)
         << new Slash(Card::Club, 4)
         << new Slash(Card::Club, 5)
         << new Slash(Card::Club, 6)
         << new Slash(Card::Club, 7)
         << new Slash(Card::Club, 8)
         << new Slash(Card::Club, 8)
         << new Slash(Card::Club, 9)
         << new Slash(Card::Club, 9)
         << new Slash(Card::Club, 10)
         << new Slash(Card::Club, 10)
         << new Slash(Card::Club, 11)
         << new Slash(Card::Club, 11)
         << new Slash(Card::Heart, 10)
         << new Slash(Card::Heart, 10)
         << new Slash(Card::Heart, 11)
         << new Slash(Card::Diamond, 6)
         << new Slash(Card::Diamond, 7)
         << new Slash(Card::Diamond, 8)
         << new Slash(Card::Diamond, 9)
         << new Slash(Card::Diamond, 10)
         << new Slash(Card::Diamond, 13);
    foreach (Card *card, cards) {
        card->setParent(this);
    }
}

ADD_PACKAGE(StandardCard)
