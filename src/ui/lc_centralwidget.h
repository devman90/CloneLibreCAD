#ifndef LC_CENTRALWIDGET_H
#define LC_CENTRALWIDGET_H

#include <QFrame>

class QMdiArea;

class LC_CentralWidget
        : public QFrame
{
public:
    explicit LC_CentralWidget(QWidget* parent = 0);

    QMdiArea* getMdiArea();

private:
    QMdiArea* mdiarea;
};

#endif // LC_CENTRALWIDGET_H
