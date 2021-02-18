#include "card.h"

Card::Card(Suit suit, int number, bool target_fixed)
    :target_fixed(target_fixed), mute(false),
    will_throw(true), has_preact(false), can_recast(false), transferable(false),
    m_suit(suit), m_number(number), m_id(-1)
{
    handling_method = will_throw ? Card::MethodDiscard : Card::MethodUse;
}
