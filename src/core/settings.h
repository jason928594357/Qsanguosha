#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QRectF>

class Settings :public QSettings {
    Q_OBJECT

public:
    explicit Settings();
    const QRectF Rect;
};

#endif // SETTINGS_H
