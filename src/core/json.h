#ifndef JSON_H
#define JSON_H

#include <QVariant>
#include <QByteArray>

typedef QVariantList JsonArray;
typedef QVariantMap JsonObject;

class JsonDocument
{
public:
    JsonDocument();
    JsonDocument(const QVariant &var);
    JsonDocument(const JsonArray &array);
    JsonDocument(const JsonObject &object);
    static JsonDocument fromFilePath(const QString &path, bool allowComment = true);
    static JsonDocument fromJson(const QByteArray &json, bool allowComment = false);
    inline JsonObject object() const {
        return value.value<JsonObject>();
    }
    inline bool isObject() const {
        return value.canConvert<JsonObject>();
    }
    inline bool isValid() const
    {
        return valid;
    }
    inline const QString errorString() const
    {
        return error;
    }
protected:
    QVariant value;
    bool valid;
    QString error;
};

namespace JsonUtils {
inline bool isString(const QVariant &var){
    return var.userType() == QMetaType::QString;
}
bool tryParse(const QVariant &var, QStringList &list);
}

#endif // JSON_H
