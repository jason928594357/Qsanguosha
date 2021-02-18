#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QByteArray>
#include <QVariant>

namespace QSanProtocol {
    enum PacketDescription {
        S_DESC_UNKNOWN,
        S_TYPE_REQUEST = 0x1,
        S_TYPE_REPLY = 0x2,
        S_TYPE_NOTIFICATION = 0x4,
        S_TYPE_MASK = 0xf,
        S_SRC_ROOM = 0x10,
        S_SRC_LOBBY = 0x20,
        S_SRC_CLIENT = 0x40,
        S_SRC_MASK = 0xf0,
        S_DEST_ROOM = 0x100,
        S_DEST_LOBBY = 0x200,
        S_DEST_CLIENT = 0x400,
        S_DEST_MASK = 0xf00,
        S_DESC_DUMMY
    };

    enum CommandType{
        S_COMMAND_UNKNOWN,
        S_COMMAND_CHOOSE_CARD,
        S_COMMAND_PLAY_CARD,
        S_COMMAND_RESPONSE_CARD,
        S_COMMAND_SHOW_CARD,
        S_COMMAND_SHOW_ALL_CARDS,
        S_COMMAND_EXCHANGE_CARD,
        S_COMMAND_DISCARD_CARD,
        S_COMMAND_INVOKE_SKILL,
        S_COMMAND_MOVE_FOCUS,
        S_COMMAND_CHOOSE_GENERAL,
        S_COMMAND_CHOOSE_KINGDOM,
        S_COMMAND_CHOOSE_SUIT,
        S_COMMAND_CHOOSE_DIRECTION,
        S_COMMAND_CHOOSE_PLAYER,
        S_COMMAND_CHOOSE_ORDER,
        S_COMMAND_ASK_PEACH,
        S_COMMAND_SET_MARK,
        S_COMMAND_SET_FLAG,
        S_COMMAND_CARD_FLAG,
        S_COMMAND_NULLIFICATION,
        S_COMMAND_MULTIPLE_CHOICE,
        S_COMMAND_PINDIAN,
        S_COMMAND_AMAZING_GRACE,
        S_COMMAND_SKILL_YIJI,
        S_COMMAND_SKILL_GUANXING,
        S_COMMAND_SKILL_GONGXIN,
        S_COMMAND_SET_PROPERTY,
        S_COMMAND_CHANGE_HP,
        S_COMMAND_CHANGE_MAXHP,
        S_COMMAND_CHEAT,
        S_COMMAND_SURRENDER,
        S_COMMAND_ENABLE_SURRENDER,
        S_COMMAND_GAME_OVER,
        S_COMMAND_GAME_START,
        S_COMMAND_MOVE_CARD,
        S_COMMAND_GET_CARD,
        S_COMMAND_LOSE_CARD,
        S_COMMAND_LOG_EVENT,
        S_COMMAND_LOG_SKILL,
        S_COMMAND_UPDATE_CARD,
        S_COMMAND_CARD_LIMITATION,
        S_COMMAND_ADD_HISTORY,
        S_COMMAND_SET_EMOTION,
        S_COMMAND_FILL_AMAZING_GRACE,
        S_COMMAND_CLEAR_AMAZING_GRACE,
        S_COMMAND_TAKE_AMAZING_GRACE,
        S_COMMAND_FIXED_DISTANCE,
        S_COMMAND_KILL_PLAYER,
        S_COMMAND_REVIVE_PLAYER,
        S_COMMAND_ATTACH_SKILL,
        S_COMMAND_NULLIFICATION_ASKED,
        S_COMMAND_EXCHANGE_KNOWN_CARDS, // For Dimeng only
        S_COMMAND_SET_KNOWN_CARDS,
        S_COMMAND_UPDATE_PILE,
        S_COMMAND_RESET_PILE,
        S_COMMAND_UPDATE_HANDCARD_NUM,
        S_COMMAND_UPDATE_STATE_ITEM,
        S_COMMAND_SPEAK,
        S_COMMAND_ARRANGE_GENERAL,
        S_COMMAND_FILL_GENERAL,
        S_COMMAND_TAKE_GENERAL,
        S_COMMAND_RECOVER_GENERAL,
        S_COMMAND_REVEAL_GENERAL,
        S_COMMAND_AVAILABLE_CARDS,
        S_COMMAND_ANIMATE,
        S_COMMAND_LUCK_CARD,
        S_COMMAND_VIEW_GENERALS,
        S_COMMAND_SET_DASHBOARD_SHADOW,
        S_COMMAND_PRESHOW,
        S_COMMAND_TOGGLE_READY,
        S_COMMAND_ADD_ROBOT,
        S_COMMAND_FILL_ROBOTS,
        S_COMMAND_TRUST,
        S_COMMAND_PAUSE,
        S_COMMAND_NETWORK_DELAY_TEST,
        S_COMMAND_CHECK_VERSION,
        S_COMMAND_SETUP,
        S_COMMAND_ADD_PLAYER,
        S_COMMAND_REMOVE_PLAYER,
        S_COMMAND_START_IN_X_SECONDS,
        S_COMMAND_ARRANGE_SEATS,
        S_COMMAND_WARN,
        S_COMMAND_SIGNUP,
        S_COMMAND_DISABLE_SHOW,
        S_COMMAND_TRIGGER_ORDER,
        S_COMMAND_MIRROR_GUANXING_STEP,
        S_COMMAND_CHANGE_SKIN,
        S_COMMAND_ENTER_LOBBY,
        S_COMMAND_ROOM_LIST,
        S_COMMAND_CREATE_ROOM,
        S_COMMAND_ENTER_ROOM
    };
    enum ServiceType {
        S_SERVICE_UNKNOWN,
        S_SERVICE_DETECT_SERVER,
        S_SERVICE_PLAYER_NUM
    };
    class Countdown {
    public:

    };
    class AbstractPacket{
    public:
        virtual bool parse(const QByteArray &) = 0;
        virtual QByteArray toJson() const = 0;
        virtual QString toString() const = 0;
        virtual PacketDescription getPacketDestination() const = 0;
        virtual PacketDescription getPacketSource() const = 0;
        virtual PacketDescription getPacketType() const = 0;
        virtual PacketDescription getPacketDescription() const = 0;
        virtual CommandType getCommandType() const = 0;
    };

    class Packet: public AbstractPacket{
    public:
        unsigned int globalSerial;
        unsigned int localSerial;
    protected:
        static unsigned int globalSerialSequence;
        CommandType command;
        PacketDescription packetDescription;
        QVariant messageBody;
        static const int S_MAX_PACKET_SIZE;
    };
}
#endif // PROTOCOL_H