#ifndef STRUCTS_H
#define STRUCTS_H


class CardMoveReason
{
public:
    CardMoveReason();
};

enum TriggerEvent{
    GameStart,
    EventPhaseStart,
    FetchDrawPileCard
};

#endif // STRUCTS_H
