#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("CloneLibreCAD");
    QCoreApplication::setApplicationName("CloneLibreCAD");
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
    QGuiApplication::setDesktopFileName("librecad.desktop");
#endif
    MainWindow w;
    w.show();
    return a.exec();
}
