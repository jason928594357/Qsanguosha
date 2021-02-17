#ifndef JSON_H
#define JSON_H

#include <QVariantList>
#include <QVariantMap>

typedef QVariantList JsonArray;
typedef QVariantMap JsonObject;

class JsonDocument{
public:
    JsonDocument();
protected:
    bool valid;
};

#endif // JSON_H
