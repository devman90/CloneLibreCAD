#ifndef QC_APPLICATIONWINDOW_H
#define QC_APPLICATIONWINDOW_H

#include "mainwindowx.h"

class QMdiArea;
class LC_PenWizard;

class QC_ApplicationWindow : public MainWindowX
{
    Q_OBJECT

public:
    QC_ApplicationWindow(QWidget *parent = nullptr);
    ~QC_ApplicationWindow();

private:
    QMdiArea* mdiAreaCAD {nullptr};

    LC_PenWizard* pen_wiz;
};

#endif // QC_APPLICATIONWINDOW_H
