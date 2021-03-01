#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QRectF>
#include <QFont>
#include <QColor>
#include <QScriptEngine>

class Settings : public QSettings {
    Q_OBJECT
public:
    explicit Settings();
    void init();

    const QRectF Rect;
    QFont bigFont;
    QFont smallFont;
    QColor textEditColor;
    QString BackgroundImage;
    bool FitInView;
    float EffectVolume;
    bool EnableEffects;
};

extern Settings Config;

#endif // SETTINGS_H
