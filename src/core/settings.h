#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QFont>
#include <QRectF>
#include <QColor>
#include <QSet>

class Settings :public QSettings {
    Q_OBJECT

public:
    explicit Settings();
    void init();

    const QRectF Rect;
    QFont BigFont;
    QFont SmallFont;
    QFont TinyFont;

    QFont AppFont;
    QFont UIFont;
    QColor TextEditColor;
    QColor SkillDescriptionInToolTipColor;
    QColor SkillDescriptionInOverviewColor;
    QColor ToolTipBackgroundColor;

    // server side
    QString ServerName;
    int CountDownSeconds;
    int NullificationCountDown;
    bool EnableMinimizeDialog;
    QString GameMode;
    QStringList BanPackages;
    bool RandomSeat;
    bool EnableCheat;
    bool FreeChoose;
    bool ForbidSIMC;
    bool DisableChat;
    QString Address;
    bool ForbidAddingRobot;
    int AIDelay;
    int OriginAIDelay;
    bool AlterAIDelayAD;
    int AIDelayAD;
    bool SurrenderAtDeath;
    int LuckCardLimitation;
    ushort ServerPort;
    bool DisableLua;
    QString RoomPassword;
    bool RewardTheFirstShowingPlayer;
    QSet<QString> BannedIp;

    // client side
    QString LobbyAddress;
    bool ConnectToLobby;
    QString HostAddress;
    QString UserName;
    QString UserAvatar;
    QStringList HistoryIPs;
    int MaxCards;

    bool EnableHotKey;
    bool NeverNullifyMyTrick;
    bool EnableAutoTarget;
    bool EnableIntellectualSelection;
    bool EnableSuperDrag;
    bool EnableDoubleClick;
    bool EnableAutoSaveRecord;
    bool NetworkOnly;
    bool EnableAutoPreshow;
    int OperationTimeout;
    bool OperationNoLimit;
    bool EnableEffects;
    bool EnableLastWord;
    bool EnableBgMusic;
    float BGMVolume;
    float EffectVolume;

    QString BackgroundImage;
    QString TableBgImage;
    QString RecordSavePath;

    int BubbleChatBoxKeepSeconds;
    bool IgnoreOthersSwitchesOfSkin;

    // consts
    static const int S_SURRENDER_REQUEST_MIN_INTERVAL;
    static const int S_PROGRESS_BAR_UPDATE_INTERVAL;
    static const int S_SERVER_TIMEOUT_GRACIOUS_PERIOD;
    static const int S_MOVE_CARD_ANIMATION_DURATION;
    static const int S_JUDGE_ANIMATION_DURATION;
    static const int S_JUDGE_LONG_DELAY;
};

extern Settings *SettingsInstance;
#define Config (*SettingsInstance)

#endif // SETTINGS_H
