#include "json.h"

#include <QFile>
#include <QJsonParseError>
#include <QJsonDocument>

JsonDocument::JsonDocument():valid(false)
{
}

JsonDocument::JsonDocument(const QVariant &var)
    : value(var), valid(true)
{
}

JsonDocument::JsonDocument(const JsonArray &array)
    :value(array),valid(true)
{
}

JsonDocument::JsonDocument(const JsonObject &object)
    :value(object),valid(true)
{
}

JsonDocument JsonDocument::fromFilePath(const QString &path, bool allowComment){
    QFile file(path);
    file.open(QFile::ReadOnly);
    return fromJson(file.readAll(),allowComment);
}

JsonDocument JsonDocument::fromJson(const QByteArray &json, bool allowComment){
    QJsonParseError error;
    QJsonDocument jsondoc = QJsonDocument::fromJson(json, &error);
    JsonDocument doc;
    if(error.error == QJsonParseError::NoError){
        doc.value = jsondoc.toVariant();
        doc.valid = true;
    } else {
        doc.valid = false;
        doc.error = error.errorString();
    }
    return doc;
}


QByteArray clearComment(const QByteArray &src){
    QByteArray result(src);
    int max = result.size() - 1;
    for (int i = 0; i < max; i++) {
        switch (result.at(i)) {
        case '/':
            if (result.at(i + 1) == '*') {
                int offset = i;
                i++;
                while (i < max && (result.at(i) != '*' || result.at(i + 1) != '/')) {
                    i++;
                }
                int length = i + 2 - offset;
                result.remove(offset, length);
                i = offset - 1;
                max -= length;
            } else if (result.at(i + 1) == '/') {
                int offset = i;
                i++;
                while (i < max + 1 && result.at(i) != '\n') {
                    i++;
                }
                int length = i + 1 - offset;
                result.remove(offset, length);
                i = offset - 1;
                max -= length;
            }
            break;
        case '"':
            while (i < max + 1 && result.at(i) != '"') {
                if (result.at(i) == '\\') {
                    i += 2;
                } else {
                    i++;
                }
            }
            break;
        default:;
        }
    }
    return result;
}

bool JsonUtils::tryParse(const QVariant &var, QStringList &list){
    return true;
}
