#include "record.h"
#include "protocol.h"

using namespace QSanProtocol;

Record::Record(QObject *parent)
    :QObject(parent), m_format(CompressedText)
{
}

Record::Record(const QString &fileName, QObject *parent)
    :QObject(parent), m_fileName(fileName), m_format(CompressedText)
{
}

bool Record::open(){
    return true;
}

Replayer::Replayer(const QString &fileName, QObject *parent)
    : QThread(parent), m_speed(1.0), m_isPlaying(true)
{
    Record *record = new Record(fileName, this);
    if (record->open())
        setRecord(record);

}

void Replayer::setRecord(Record *record){

}
