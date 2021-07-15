#include "lc_centralwidget.h"

#include <QVBoxLayout>
#include <QMdiArea>

LC_CentralWidget::LC_CentralWidget(QWidget *parent)
    : QFrame(parent)
    , mdiarea(new QMdiArea)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);

    QVBoxLayout* lyt = new QVBoxLayout;
    lyt->setContentsMargins(0, 0, 0, 0);
    lyt->addWidget(mdiarea);

    mdiarea->setObjectName("mdi_area");
    mdiarea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiarea->setFocusPolicy(Qt::ClickFocus);
    mdiarea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mdiarea->setTabsMovable(true);
    mdiarea->setTabsClosable(true);

    setLayout(lyt);
}

QMdiArea *LC_CentralWidget::getMdiArea()
{
    return mdiarea;
}
