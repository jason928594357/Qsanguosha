#ifndef RECORD_H
#define RECORD_H

#include <QObject>
#include <QThread>

class Record:public QObject {
    Q_OBJECT
public:
    enum Format{
        CompressedText
    };
    explicit Record(QObject *parent = 0);
    explicit Record(const QString &fileName, QObject *parent = 0);
public slots:
    bool open();
private:
    Format m_format;
    QString m_fileName;
};

class Replayer:public QThread{
    Q_OBJECT
public:
    explicit Replayer(const QString &fileName, QObject *parent);
    void setRecord(Record *record);
private:
    qreal m_speed;
    bool m_isPlaying;
};
#endif // RECORD_H
