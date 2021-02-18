#ifndef PLAYER_H
#define PLAYER_H

#include "general.h"
#include "wrappedcard.h"
#include "namespace.h"

#include <QObject>

class EquipCard;
class Weapon;
class Armor;
class Horse;
class DelayedTrick;
class DistanceSkill;
class TriggerSkill;

class Player : public QObject {
    Q_OBJECT

public:
    enum Phase {
        // 回合开始阶段
        RoundStart,
        Start,
        Judge,
        Draw,
        Play,
        Discard,
        Finish,
        NotActive,
        PhaseNone
    };

    enum Place{
        PlaceHand,
        PlaceEquip,
        PlaceDelayedTrick,
        PlaceJudge,
        PlaceSpecial,
        DiscardPile,
        DrawPile,
        PlaceTable,
        PlaceUnknown,
        PlaceWuGu,
        DrawPileBottom
    };

    explicit Player(QObject *parent);
protected:
    const General *general,*general2;
    int headSkinId, deputySkinId;

private:
    bool owner;
    General::Gender m_gender;
    int hp, max_hp;
    bool role_shown;
    QString state;
    int seat;
    bool alive;
    const General *actual_general1, *actual_general2;
    bool general1_showed, general2_showed;
    Phase phase;
    WrappedCard *weapon, *armor, *defensive_horse, *offensive_horse, *treasure;
    bool face_up;
    bool chained;
    bool removed;
    bool scenario_role_shown;
};

#endif // PLAYER_H
