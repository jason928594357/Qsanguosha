#include "player.h"

Player::Player(QObject *parent)
    :QObject(parent),general(NULL),general2(NULL),
      headSkinId(0),deputySkinId(0),owner(false),
      m_gender(General::Sexless), hp(-1), max_hp(-1),
      role_shown(false), state("online"), seat(0), alive(true),
      actual_general1(NULL), actual_general2(NULL),
      general1_showed(false), general2_showed(false),
      phase(NotActive),
      weapon(NULL), armor(NULL), defensive_horse(NULL), offensive_horse(NULL), treasure(NULL),
      face_up(true), chained(false), removed(false), scenario_role_shown(false)
{
}
