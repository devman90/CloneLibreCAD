#ifndef QC_APPLICATIONWINDOW_H
#define QC_APPLICATIONWINDOW_H

#include "mainwindowx.h"

class QC_ApplicationWindow : public MainWindowX
{
    Q_OBJECT

public:
    QC_ApplicationWindow(QWidget *parent = nullptr);
    ~QC_ApplicationWindow();
};

#endif // QC_APPLICATIONWINDOW_H
