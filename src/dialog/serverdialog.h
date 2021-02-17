#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include "flatdialog.h"

#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>
#include <QLabel>

class QLineEdit;

class ServerDialog : public FlatDialog {
    Q_OBJECT
public:
    ServerDialog(QWidget *parent);
    bool config();

private:
    QLineEdit *server_name_edit;
    QSpinBox *timeout_spinbox;
    QCheckBox *nolimit_checkbox;
    QCheckBox *random_seat_checkbox;
    QCheckBox *enable_cheat_checkbox;
    QCheckBox *free_choose_checkbox;
    QLabel *pile_swapping_label;
    QSpinBox *pile_swapping_spinbox;
    QCheckBox *forbid_same_ip_checkbox;
    QCheckBox *disable_chat_checkbox;
    QLabel *hegemony_maxchoice_label;
    QSpinBox *hegemony_maxchoice_spinbox;
    QPushButton *mini_scene_button;
    QLineEdit *address_edit;
    QLineEdit *port_edit;
    QSpinBox *game_start_spinbox;
    QSpinBox *nullification_spinbox;
    QCheckBox *minimize_dialog_checkbox;
    QCheckBox *reward_the_first_showing_player_checkbox;
    QCheckBox *forbid_adding_robot_checkbox;
    QSpinBox *ai_delay_spinbox;
    QCheckBox *ai_delay_altered_checkbox;
    QSpinBox *ai_delay_ad_spinbox;
    QCheckBox *surrender_at_death_checkbox;
    QLabel *luck_card_label;
    QSpinBox *luck_card_spinbox;
    QCheckBox *disable_lua_checkbox;
    QLineEdit *lobby_address_edit;
    QCheckBox *connect_to_lobby_checkbox;
    QLineEdit *room_password_edit;
    QButtonGroup *extension_group;
    QButtonGroup *mode_group;
    QCheckBox *convert_ds_to_dp;
    QCheckBox *convert_lord;
    QCheckBox *ai_chat_checkbox;
};

#endif // SERVERDIALOG_H
