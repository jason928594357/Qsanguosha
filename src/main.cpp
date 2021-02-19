#include <QFile>
#include <QCoreApplication>
#include <QApplication>
#include <QTranslator>
#include <QDateTime>
#include <QSplashScreen>
#include <QMessageBox>
#include <QDir>

#include "server.h"
#include "settings.h"
#include "engine.h"
#include "mainwindow.h"
#include "audio.h"
#include "stylehelper.h"

int main(int argc, char *argv[]) {
    bool noGui = argc > 1 && strcmp(argv[1], "-server") == 0;
    if (noGui)
        new QCoreApplication(argc, argv);
    else
        new QApplication(argc, argv);
    QSplashScreen *splash = NULL;
    if (!noGui) {
        QPixmap raraLogo("image/system/developers/logo.png");
        splash = new QSplashScreen(raraLogo);
        splash->show();
        qApp->processEvents();
    }
#define showSplashMessage(message) \
    if (splash == NULL) {\
        puts(message.toUtf8().constData());\
    } else {\
        splash->showMessage(message, Qt::AlignBottom | Qt::AlignHCenter, Qt::cyan);\
        qApp->processEvents();\
    }

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QTranslator translator;
    translator.load("sanguosha.qm");
    qApp->installTranslator(&translator);

    showSplashMessage(QSplashScreen::tr("Loading translation..."));
    QTranslator qt_translator;
    qt_translator.load("qt_zh_CN.qm");
    qApp->installTranslator(&qt_translator);

    showSplashMessage(QSplashScreen::tr("Loading user's configurations..."));
    new Settings;
    Config.init();
    if (!noGui)
        qApp->setFont(Config.AppFont);

    showSplashMessage(QSplashScreen::tr("Initializing game engine..."));
    new Engine;

    if (qApp->arguments().contains("-server")) {
        Server *server = new Server(qApp);
        server->listen(QHostAddress::Any, Config.ServerPort);
        return qApp->exec();
    }

    showSplashMessage(QSplashScreen::tr("Loading style sheet..."));
    QFile file("style-sheet/sanguosha.qss");
    QString styleSheet;
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        styleSheet = stream.readAll();
    }


    QFile winFile("style-sheet/windows-extra.qss");
    if (winFile.open(QIODevice::ReadOnly)) {
        QTextStream winStream(&winFile);
        styleSheet += winStream.readAll();
    }

    qApp->setStyleSheet(styleSheet + StyleHelper::styleSheetOfTooltip());

    showSplashMessage(QSplashScreen::tr("Initializing audio module..."));
    Audio::init();
    showSplashMessage(QSplashScreen::tr("Loading main window..."));
    MainWindow main_window;
    Sanguosha->setParent(&main_window);
    main_window.show();
    if (splash != NULL) {
        splash->finish(&main_window);
        delete splash;
    }
    foreach (const QString &arg, qApp->arguments()) {
        if (arg.startsWith("-connect:")) {
            Config.HostAddress = arg.mid(9);
            Config.setValue("HostAddress", Config.HostAddress);
            main_window.startConnection();
            break;
        }
    }
    return qApp->exec();
}
