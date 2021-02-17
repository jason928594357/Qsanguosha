#include "serverdialog.h"
#include "settings.h"
#include "engine.h"

#include <QButtonGroup>

ServerDialog::ServerDialog(QWidget *parent)
    :FlatDialog(parent)
{
    setWindowTitle(tr("Start room server"));
}

bool ServerDialog::config(){
    exec();
    if(result() !=Accepted){
        return false;
    }
    Config.ServerName = server_name_edit->text();
    Config.OperationTimeout = timeout_spinbox->value();
    Config.OperationNoLimit = nolimit_checkbox->isChecked();
    Config.RandomSeat = random_seat_checkbox->isChecked();
    Config.EnableCheat = enable_cheat_checkbox->isChecked();
    Config.FreeChoose = Config.EnableCheat && free_choose_checkbox->isChecked();
    Config.ForbidSIMC = forbid_same_ip_checkbox->isChecked();
    Config.DisableChat = disable_chat_checkbox->isChecked();
    Config.Address = address_edit->text();
    Config.CountDownSeconds = game_start_spinbox->value();
    Config.NullificationCountDown = nullification_spinbox->value();
    Config.EnableMinimizeDialog = minimize_dialog_checkbox->isChecked();
    Config.RewardTheFirstShowingPlayer = reward_the_first_showing_player_checkbox->isChecked();
    Config.ForbidAddingRobot = forbid_adding_robot_checkbox->isChecked();
    Config.OriginAIDelay = ai_delay_spinbox->value();
    Config.AIDelay = Config.OriginAIDelay;
    Config.AIDelayAD = ai_delay_ad_spinbox->value();
    Config.AlterAIDelayAD = ai_delay_altered_checkbox->isChecked();
    Config.ServerPort = port_edit->text().toUShort();
    Config.DisableLua = disable_lua_checkbox->isChecked();
    Config.SurrenderAtDeath = surrender_at_death_checkbox->isChecked();
    Config.LuckCardLimitation = luck_card_spinbox->value();
    Config.LobbyAddress = lobby_address_edit->text();
    Config.ConnectToLobby = connect_to_lobby_checkbox->isChecked();
    Config.RoomPassword = room_password_edit->text();

    // game mode
    QString objname = mode_group -> checkedButton() -> objectName();
    Config.GameMode = objname;

    Config.setValue("ServerName", Config.ServerName);
    Config.setValue("GameMode", Config.GameMode);
    Config.setValue("OperationTimeout", Config.OperationTimeout);
    Config.setValue("OperationNoLimit", Config.OperationNoLimit);
    Config.setValue("RandomSeat", Config.RandomSeat);
    Config.setValue("EnableCheat", Config.EnableCheat);
    Config.setValue("FreeChoose", Config.FreeChoose);
    Config.setValue("PileSwappingLimitation", pile_swapping_spinbox->value());
    Config.setValue("ForbidSIMC", Config.ForbidSIMC);
    Config.setValue("DisableChat", Config.DisableChat);
    Config.setValue("HegemonyMaxChoice", hegemony_maxchoice_spinbox->value());
    Config.setValue("CountDownSeconds", game_start_spinbox->value());
    Config.setValue("NullificationCountDown", nullification_spinbox->value());
    Config.setValue("EnableMinimizeDialog", Config.EnableMinimizeDialog);
    Config.setValue("RewardTheFirstShowingPlayer", Config.RewardTheFirstShowingPlayer);
    Config.setValue("ForbidAddingRobot", Config.ForbidAddingRobot);
    Config.setValue("OriginAIDelay", Config.OriginAIDelay);
    Config.setValue("AlterAIDelayAD", ai_delay_altered_checkbox->isChecked());
    Config.setValue("AIDelayAD", Config.AIDelayAD);
    Config.setValue("SurrenderAtDeath", Config.SurrenderAtDeath);
    Config.setValue("LuckCardLimitation", Config.LuckCardLimitation);
    Config.setValue("ServerPort", Config.ServerPort);
    Config.setValue("Address", Config.Address);
    Config.setValue("DisableLua", disable_lua_checkbox->isChecked());
    Config.setValue("AIChat", ai_chat_checkbox->isChecked());
    Config.setValue("LobbyAddress", Config.LobbyAddress);
    Config.setValue("ConnectToLobby", Config.ConnectToLobby);

    QSet<QString> ban_packages;
    QList<QAbstractButton *> checkboxes = extension_group->buttons();
    foreach (QAbstractButton *checkbox, checkboxes) {
        if (!checkbox->isChecked()) {
            QString package_name = checkbox->objectName();
            Sanguosha->addBanPackage(package_name);
            ban_packages.insert(package_name);
        }
    }

    Config.BanPackages = ban_packages.toList();
    Config.setValue("BanPackages", Config.BanPackages);

    Config.setValue("EnableLordConvertion", convert_lord->isChecked());

    QStringList card_conversions;
    if (convert_ds_to_dp->isChecked()){
        card_conversions << "DragonPhoenix";
    }
    Config.setValue("CardConversions", card_conversions);

    return true;
}
