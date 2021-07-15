#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QSettings>
#include <QPixmap>
#include "lib/debug/rs_debug.h"

void testDebug() {
    RS_DEBUG("Debug %d %d %d", 3, 2, 1);
    RS_DEBUG_VERBOSE("Debug %d %d %d", 3, 2, 1);
    RS_Debug::instance()->setLevel(RS_Debug::D_ERROR);
    RS_DEBUG("Debug %d %d %d", 3, 2, 1);
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("CloneLibreCAD");
    QCoreApplication::setApplicationName("CloneLibreCAD");
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
    QGuiApplication::setDesktopFileName("librecad.desktop");
#endif

    QSettings settings;
    QSplashScreen* splash = new QSplashScreen;
    bool showSplash = settings.value("Startup/ShowSplash", 1).toBool();
    if (showSplash) {
        QPixmap pixmap(":/main/splash_librecad.png");
        splash->setPixmap(pixmap);
        splash->setAttribute(Qt::WA_DeleteOnClose);
        splash->show();
        splash->showMessage(QObject::tr("Loading..."),
                            Qt::AlignRight|Qt::AlignBottom, Qt::black);
        app.processEvents();
        RS_DEBUG("main: spalshscreen: OK");
    }

    MainWindow w;
    w.show();
    w.setFocus();

    if (showSplash) {
        splash->finish(&w);
    } else {
        delete splash;
    }

    testDebug();

    RS_DEBUG("main: entering Qt event loop");
    int returnCode = app.exec();
    RS_DEBUG("main: exited Qt event loop");
    return returnCode;
}
