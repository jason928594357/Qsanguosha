#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    new QApplication(argc,argv);
    MainWindow *main_window = new MainWindow;
    main_window->show();
    return qApp->exec();
}
