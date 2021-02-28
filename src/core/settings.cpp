#include "settings.h"

#include <QFontDatabase>

Settings Config;

static const qreal ViewWidth = 1280 * 0.8;
static const qreal ViewHeight = 800 * 0.8;

Settings::Settings() :
    QSettings("config.ini", QSettings::IniFormat),
    Rect(-ViewWidth/2, -ViewHeight/2, ViewWidth, ViewHeight)
{
}


void Settings::init(){
    QString font_path = value("DefaultFontPath", "font/simli.ttf").toString();
    int font_id = QFontDatabase::addApplicationFont(font_path);
    if(font_id!=-1){
        QString font_family = QFontDatabase::applicationFontFamilies(font_id).front();
        bigFont.setFamily(font_family);
        smallFont.setFamily(font_family);
    }
    BackgroundImage = value("BackgroundImage", "image/system/backdrop/default.jpg").toString();
}
