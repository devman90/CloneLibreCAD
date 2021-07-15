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
    QApplication a(argc, argv);
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
        splash->showMessage("Loading...");
        RS_DEBUG("main: spalshscreen: OK");
    }

    MainWindow w;
    w.show();

    testDebug();
    return a.exec();
}
