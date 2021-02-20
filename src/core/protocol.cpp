#include "protocol.h"
#include "json.h"

using namespace QSanProtocol;

QSanProtocol::Packet::Packet(int packetDescription, CommandType command)
    : globalSerial(0), localSerial(0),
      command(command),
      packetDescription(static_cast<PacketDescription>(packetDescription))
{
}
