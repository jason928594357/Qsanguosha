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

Jink::Jink(Card::Suit suit, int number):BasicCard(suit,number){
    setObjectName("jink");
}

QString Jink::getSubtype() const{
    return tr("defense card");
}

QString Jink::getDescription() const{
    QString description = tr("<b>【Jink】</b>Basic card<br /><b>Phase</b>:【Slash】when it takes effect for you<br /><b>Target</b>:this【Slash】<br /><b>Effect</b>:offset the effect of this【Slash】.");
    return description;
}

QString Jink::getCardName() const {
    return tr("jink");
}

QString Jink::getPackageName() const {
    return tr("standard card");
}

Peach::Peach(Card::Suit suit, int number):BasicCard(suit,number){
    setObjectName("peach");
}

QString Peach::getSubtype() const{
    return tr("recover card");
}

QString Peach::getDescription()const{
    QString description = tr("<b>【Peach】</b>Basic card<br /><b>Phase</b>:play phase/when a role is on the verge of death<br /><b>Target</b>:have hurt you/thr role on the verge of death<br /><b>Effect</b>:the target role returns to a point blood.");
    return description;
}

QString Peach::getCardName() const {
    return tr("peach");
}

QString Peach::getPackageName() const {
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
         << new Slash(Card::Diamond, 13)
         << new Jink(Card::Heart, 2)
         << new Jink(Card::Heart, 2)
         << new Jink(Card::Heart, 13)
         << new Jink(Card::Diamond, 2)
         << new Jink(Card::Diamond, 2)
         << new Jink(Card::Diamond, 3)
         << new Jink(Card::Diamond, 4)
         << new Jink(Card::Diamond, 5)
         << new Jink(Card::Diamond, 6)
         << new Jink(Card::Diamond, 7)
         << new Jink(Card::Diamond, 8)
         << new Jink(Card::Diamond, 9)
         << new Jink(Card::Diamond, 10)
         << new Jink(Card::Diamond, 11)
         << new Jink(Card::Diamond, 11)
         << new Peach(Card::Heart, 3)
         << new Peach(Card::Heart, 4)
         << new Peach(Card::Heart, 6)
         << new Peach(Card::Heart, 7)
         << new Peach(Card::Heart, 8)
         << new Peach(Card::Heart, 9)
         << new Peach(Card::Heart, 12)
         << new Peach(Card::Diamond, 12);
    foreach (Card *card, cards) {
        card->setParent(this);
    }
}

ADD_PACKAGE(StandardCard)
