#ifndef JSON_H
#define JSON_H

#include <QVariantList>
#include <QVariantMap>

typedef QVariantList JsonArray;
typedef QVariantMap JsonObject;

class JsonDocument{
public:
    JsonDocument();
    JsonDocument(const QVariant &var);
protected:
    QVariant value;
    bool valid;
    QString error;
};

namespace JsonUtils {
    inline bool isString(const QVariant &var) {
        return var.userType() == QMetaType::QString;
    }
}

#endif // JSON_H
