#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    new QApplication(argc,argv);
    QTranslator translator;
    translator.load("sanguosha.qm");
    qApp->installTranslator(&translator);
    MainWindow *main_window = new MainWindow;
    main_window->show();
    return qApp->exec();
}
