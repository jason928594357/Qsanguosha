#include "clientstruct.h"

#include <QFormLayout>

RoomInfoStruct ServerInfo;

ServerInfoWidget::ServerInfoWidget(bool show_lack) {
    name_label = new QLabel;
    address_label = new QLabel;
    port_label = new QLabel;
    game_mode_label = new QLabel;
    player_count_label = new QLabel;
    random_seat_label = new QLabel;
    enable_cheat_label = new QLabel;
    free_choose_label = new QLabel;
    forbid_adding_robot_label = new QLabel;
    fisrt_showing_reward_label = new QLabel;
    time_limit_label = new QLabel;

    list_widget = new QListWidget;
    list_widget->setViewMode(QListView::IconMode);
    list_widget->setMovement(QListView::Static);

    QFormLayout *layout = new QFormLayout;
    layout->addRow(tr("Server name"), name_label);
    layout->addRow(tr("Address"), address_label);
    layout->addRow(tr("Port"), port_label);
    layout->addRow(tr("Game mode"), game_mode_label);
    layout->addRow(tr("Player count"), player_count_label);
    layout->addRow(tr("Random seat"), random_seat_label);
    layout->addRow(tr("Enable cheat"), enable_cheat_label);
    layout->addRow(tr("Free choose"), free_choose_label);
    layout->addRow(tr("Forbid adding robot"), forbid_adding_robot_label);
    layout->addRow(tr("Enable First Showing Reward"), fisrt_showing_reward_label);
    layout->addRow(tr("Operation time"), time_limit_label);
    layout->addRow(tr("Extension packages"), list_widget);

    if (show_lack) {
        lack_label = new QLabel;
        layout->addRow(tr("Lack"), lack_label);
    }
    else
        lack_label = NULL;

    setLayout(layout);
}
