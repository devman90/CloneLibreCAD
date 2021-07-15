#include "mainwindow.h"

#include <QApplication>
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

    testDebug();

    MainWindow w;
    w.show();
    return a.exec();
}
