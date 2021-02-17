#include "stylehelper.h"
#include "engine.h"
#include "util.h"

#include <QApplication>
#include <QPushButton>
#include <QTextStream>

StyleHelper *StyleHelper::instance = NULL;

StyleHelper::StyleHelper(QObject *):
    QObject(qApp)
{
    iconFont = getFontByFileName("fontawesome-webfont.ttf");
}

StyleHelper *StyleHelper::getInstance(){
    static QMutex mutex;
    if(!instance){
        QMutexLocker locker(&mutex);
        if(!instance){
            instance = new StyleHelper;
        }
    }
    return instance;
}

QFont StyleHelper::getFontByFileName(const QString &fileName){

}

QString StyleHelper::styleSheetOfScrollBar(){
    static QString style;
    if(style.isEmpty()){
        QFile file("style-sheet/scroll.qss");
        if(file.open(QIODevice::ReadOnly)){
            QTextStream stream(&file);
            style = stream.readAll();
        }
    }
    return style;
}

QColor StyleHelper::backgroundColorOfFlatDialog()
{
    static QColor color;
    static bool loaded = false;
    if (!loaded) {
        lua_State *L = Sanguosha->getLuaState();
        const QString colorString = GetConfigFromLuaState(L, "dialog_background_color").toString();
        color.setNamedColor(colorString);
        if (!color.isValid()) {
            qWarning("Invalid color for dialog background");
            color.setRgb(214, 231, 239);
        }
        const int alpha = GetConfigFromLuaState(L, "dialog_background_alpha").toInt();
        color.setAlpha(qBound(0, alpha, 255));
        loaded = true;
    }
    return color;
}

void StyleHelper::setIcon(QPushButton* button, QChar iconId, int size) {
    iconFont.setPointSize(size);
    button->setFont(iconFont);
    button->setText(iconId);
}
