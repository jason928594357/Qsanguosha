#ifndef ROOMCONFIG_H
#define ROOMCONFIG_H

#include "protocol.h"

class Settings;

struct RoomInfoStruct{
    RoomInfoStruct();
    RoomInfoStruct(const Settings *config);

};
#endif // ROOMCONFIG_H
