RESOURCES += ../res/main/main.qrc

CONFIG += c++11
QT += widgets
TEMPLATE = app
TARGET = LibreCAD

HEADERS += \
    main/mainwindowx.h \
    main/qc_applicationwindow.h \
    lib/debug/rs_debug.h \
    lib/printing/lc_printing.h

SOURCES += \
    main/main.cpp \
    main/mainwindowx.cpp \
    main/qc_applicationwindow.cpp \
    lib/debug/rs_debug.cpp \
    lib/printing/lc_printing.cpp

FORMS +=
