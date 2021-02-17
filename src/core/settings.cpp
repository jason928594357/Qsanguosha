#include "settings.h"

#include <QApplication>

Settings *SettingsInstance = NULL;

static const qreal ViewWidth = 1280 * 0.8;
static const qreal ViewHeight = 800 * 0.8;

Settings::Settings()
#ifdef Q_OS_WIN32
    : QSettings("config.ini", QSettings::IniFormat),
#else
    : QSettings("QSanguosha.org", "QSanguosha"),
#endif
    Rect(-ViewWidth / 2, -ViewHeight / 2, ViewWidth, ViewHeight)
{
    Q_ASSERT(SettingsInstance == NULL);
    SettingsInstance = this;
    connect(qApp, &QApplication::aboutToQuit, this, &Settings::deleteLater);
}
