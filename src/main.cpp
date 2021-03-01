#include "mainwindow.h"
#include "audio.h"
#include "settings.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    new QApplication(argc,argv);
    QTranslator translator;
    translator.load("sanguosha.qm");
    qApp->installTranslator(&translator);
    Audio::init();
    MainWindow *main_window = new MainWindow;
    main_window->show();
    return qApp->exec();
}
