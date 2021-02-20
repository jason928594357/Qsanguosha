#ifndef CLIENT_H
#define CLIENT_H

#include "protocol.h"
#include "roomstate.h"
#include "abstractclientsocket.h"
#include "record.h"

#include <QObject>
#include <QTextDocument>

class Recorder;
class Replayer;
class AbstractUdpSocket;

class Client : public QObject {
    Q_OBJECT
    Q_PROPERTY(Client::Status status READ getStatus WRITE setStatus)
    Q_ENUMS(Status)
public:
    enum Status {
        NotActive = 0x010000,
        Responding = 0x000001,
        Playing = 0x000002,
        Discarding = 0x000003,
        Exchanging = 0x000004,
        ExecDialog = 0x000005,
        AskForSkillInvoke = 0x000006,
        AskForAG = 0x000007,
        AskForPlayerChoose = 0x000008,
        AskForYiji = 0x000009,
        AskForGuanxing = 0x00000A,
        AskForGongxin = 0x00000B,
        AskForShowOrPindian = 0x00000C,
        AskForGeneralChosen = 0x01000D,
        AskForArrangement = 0x00000E,
        AskForChoice = 0x01000F,
        AskForTriggerOrder = 0x010010,
        AskForCardChosen = 0x010011,
        AskForSuit = 0x010012,
        RespondingUse = 0x000101,
        RespondingForDiscard = 0x000201,
        RespondingNonTrigger = 0x000301,
        ClientStatusBasicMask = 0xFF00FF,
        ClientStatusFeatureMask = 0xFF0000,
        StatusHasOwnProgressBar = 0x010000
    };
    explicit Client(QObject *parent, const QString &filename = QString());
    ~Client();
    typedef void (Client::*Callback) (const QVariant &);

    void checkVersion(const QVariant &server_version);

    void notifyServer(QSanProtocol::CommandType command, const QVariant &arg = QVariant());
    void setStatus(Status status);
    Status getStatus() const;
    bool m_isDiscardActionRefusable;
    void speakToServer(const QString &text);
    bool m_noNullificationThisTime;
    QString m_noNullificationTrickName;

protected:
    Status status;
    int alive_count;
    int swap_pile;
    RoomState _m_roomState;

private:
    AbstractClientSocket *socket;
    bool m_isGameOver;
    static QHash<QSanProtocol::CommandType, Callback> callbacks;
    Recorder *recorder;
    Replayer *replayer;
    QTextDocument *lines_doc,*prompt_doc;
    AbstractUdpSocket *detector;
private slots:
    void processServerPacket(const QByteArray &cmd);
    void processDatagram(const QByteArray &data, const QHostAddress &from, ushort port);
signals:
    void version_checked(const QString &version_number, const QString &mod_name);
    void lineSpoken(const QString &line);
};

extern Client *ClientInstance;

#endif // CLIENT_H
