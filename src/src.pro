RESOURCES += ../res/main/main.qrc

CONFIG += c++11
QT += widgets
TEMPLATE = app
TARGET = LibreCAD

HEADERS += \
    mainwindow.h \
    lib/debug/rs_debug.h \
    lib/printing/lc_printing.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    lib/debug/rs_debug.cpp \
    lib/printing/lc_printing.cpp 

FORMS += \
    mainwindow.ui
