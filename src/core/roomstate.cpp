#include "roomstate.h"

RoomState::~RoomState() {
    foreach (WrappedCard *card, m_cards) {
        delete card;
    }
    m_cards.clear();
}
