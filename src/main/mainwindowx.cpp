#include "mainwindowx.h"

#include <QDockWidget>
#include <QToolBar>

namespace Sorting
{
    bool byWindowTitle(QWidget* left, QWidget* right) {
        return left->windowTitle() < right->windowTitle();
    }
}

MainWindowX::MainWindowX(QWidget *parent)
    : QMainWindow(parent)
{

}

void MainWindowX::sortWidgetsByTitle(QList<QDockWidget *> &list)
{
    std::sort(list.begin(), list.end(), Sorting::byWindowTitle);
}

void MainWindowX::sortWidgetsByTitle(QList<QToolBar *> &list)
{
    std::sort(list.begin(), list.end(), Sorting::byWindowTitle);
}

void MainWindowX::toggleRightDockArea(bool state)
{
    for (QDockWidget* dw : findChildren<QDockWidget*>()) {
        if (dockWidgetArea(dw) == Qt::LeftDockWidgetArea && !dw->isFloating()) {
            dw->setVisible(state);
        }
    }
}

void MainWindowX::toggleLeftDockArea(bool state)
{
    for (QDockWidget* dw : findChildren<QDockWidget*>()) {
        if (dockWidgetArea(dw) == Qt::RightDockWidgetArea && !dw->isFloating()) {
            dw->setVisible(state);
        }
    }
}

void MainWindowX::toggleTopDockArea(bool state)
{
    for (QDockWidget* dw : findChildren<QDockWidget*>()) {
        if (dockWidgetArea(dw) == Qt::TopDockWidgetArea && !dw->isFloating()) {
            dw->setVisible(state);
        }
    }
}

void MainWindowX::toggleBottomDockArea(bool state)
{
    for (QDockWidget* dw : findChildren<QDockWidget*>()) {
        if (dockWidgetArea(dw) == Qt::BottomDockWidgetArea && !dw->isFloating()) {
            dw->setVisible(state);
        }
    }
}

void MainWindowX::toggleFloatingDockWidgets(bool state)
{
    for (QDockWidget* dw : findChildren<QDockWidget*>()) {
        if (dw->isFloating()) {
            dw->setVisible(state);
        }
    }
}
