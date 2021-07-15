#include "qc_applicationwindow.h"
#include <QMdiArea>
#include <QString>
#include "ui/lc_centralwidget.h"
#include "ui/lc_penwizard.h"

QC_ApplicationWindow::QC_ApplicationWindow(QWidget *parent)
    : MainWindowX(parent)
    , pen_wiz(new LC_PenWizard(QObject::tr("Pen Wizard"), this))
{
    LC_CentralWidget* centralWidget = new LC_CentralWidget;
    setCentralWidget(centralWidget);
    mdiAreaCAD = centralWidget->getMdiArea();

    setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    pen_wiz->setObjectName("pen_wiz");
    addDockWidget(Qt::RightDockWidgetArea, pen_wiz);
}

QC_ApplicationWindow::~QC_ApplicationWindow()
{
}

