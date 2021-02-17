#include <QCoreApplication>
#include <QApplication>

#include "mainwindow.h"
#include "engine.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow main_window;
    //Sanguosha->setParent(&main_window);
    main_window.show();

    return qApp->exec();
}
