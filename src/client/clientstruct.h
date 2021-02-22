#ifndef CLIENTSTRUCT_H
#define CLIENTSTRUCT_H

#include "roomconfig.h"

#include <QWidget>
#include <QLabel>
#include <QListWidget>

extern RoomInfoStruct ServerInfo;

class ServerInfoWidget : public QWidget {
    Q_OBJECT

public:
    ServerInfoWidget(bool show_lack = false);

private:
    QLabel *name_label;
    QLabel *address_label;
    QLabel *port_label;
    QLabel *game_mode_label;
    QLabel *player_count_label;
    QLabel *random_seat_label;
    QLabel *enable_cheat_label;
    QLabel *free_choose_label;
    QLabel *forbid_adding_robot_label;
    QLabel *fisrt_showing_reward_label;
    QLabel *time_limit_label;
    QLabel *lack_label;
    QListWidget *list_widget;
};

#endif // CLIENTSTRUCT_H
