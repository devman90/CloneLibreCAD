#ifndef LC_PENWIZARD_H
#define LC_PENWIZARD_H

#include <QDockWidget>
#include <QString>

class LC_PenWizard
        : public QDockWidget
{
    Q_OBJECT

public:
    LC_PenWizard(const QString& title, QWidget* parent = 0);
};

#endif // LC_PENWIZARD_H
