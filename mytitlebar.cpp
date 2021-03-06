#include "mytitlebar.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>
#include<QDebug>

myTitle::myTitle(QWidget*parent):QWidget(parent)
{
    setFixedHeight(30);

     //pParent->setWindowFlags(Qt::X11BypassWindowManagerHint);
       pParent=parent;

        pParent->setAutoFillBackground(true);
        QPalette palette;
        QPixmap pixmap(":/images/res/start.png");
        palette.setBrush(QPalette::Window,QBrush(pixmap));
        pParent->setPalette(palette);

       int height=pParent->height();
       int width=pParent->width();

       m_pIconLabel = new QLabel(this);
       m_pTitleLabel = new QLabel(this);
       m_pMinimizeButton = new QPushButton(this);
       m_pMaximizeButton = new QPushButton(this);
       m_pCloseButton = new QPushButton(this);

       m_pIconLabel->setFixedSize(20, 20);
       m_pIconLabel->setScaledContents(true);

       m_pTitleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

       m_pMinimizeButton->setFixedSize(27, 22);
       m_pMaximizeButton->setFixedSize(27, 22);
       m_pCloseButton->setFixedSize(27, 22);

       m_pTitleLabel->setObjectName("whiteLabel");
       m_pMinimizeButton->setObjectName("minimizeButton");
       m_pMaximizeButton->setObjectName("maximizeButton");
       m_pCloseButton->setObjectName("closeButton");

       m_pMinimizeButton->setToolTip("Minimize");
       m_pMaximizeButton->setToolTip("Maximize");
       m_pCloseButton->setToolTip("Close");
        QPixmap image0(":/images/res/min.png");
        QPixmap image=image0.scaled(20,20);
        qDebug() << image.size();
       m_pMinimizeButton->setIcon(QIcon(image));

       m_pCloseButton->setIcon(QPixmap(":/images/res/close.png"));
       m_pMaximizeButton->setIcon(QPixmap(":/images/res/max.png"));

       m_pCloseButton->setStyleSheet("QPushButton{background-color: rgb(224,255,255);}");
       m_pMinimizeButton->setStyleSheet("QPushButton{background-color: rgb(224,255,255);}");
       m_pMaximizeButton->setStyleSheet("QPushButton{background-color: rgb(224,255,255);}");

       QHBoxLayout *pLayout = new QHBoxLayout(this);
       pLayout->addWidget(m_pIconLabel);
       pLayout->addSpacing(5);
       pLayout->addWidget(m_pTitleLabel);
       pLayout->addWidget(m_pMinimizeButton);
       pLayout->addWidget(m_pMaximizeButton);
       pLayout->addWidget(m_pCloseButton);
       pLayout->setSpacing(0);
       pLayout->setContentsMargins(5, 0, 5, 0);

       setLayout(pLayout);
       connect(m_pMinimizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
       connect(m_pMaximizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
       connect(m_pCloseButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
}

void myTitle::mouseDoubleClickEvent(QMouseEvent *event){
    Q_UNUSED(event);
    emit m_pMaximizeButton->clicked();
}
/*
void myTitle::mousePressEvent(QMouseEvent *event){
#ifdef Q_OS_WIN
    if(ReleaseCapture()){
            QWidget*pWindow=this->window();
            if(pWindow->isTopLevel()){
                SendMessage(HWND(pWindow->winId()),WM_SYSCOMMAND,SC_MOVE+HTCAPTION,0);
            }
    }
    event->ignore();

#else
#endif
}
*/
/*bool myTitle::eventFilter(QObject *watched, QEvent *event){
    switch (event->type())
    {
    case QEvent::WindowTitleChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            m_pTitleLabel->setText(pWidget->windowTitle());
            return true;
        }
    }
    case QEvent::WindowIconChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            QIcon icon = pWidget->windowIcon();
            m_pIconLabel->setPixmap(icon.pixmap(m_pIconLabel->size()));
            return true;
        }
    }
    case QEvent::WindowStateChange:
    case QEvent::Resize:
        updateMaximize();
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void myTitle::onClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        if (pButton == m_pMinimizeButton)
        {
            pWindow->showMinimized();
        }
        else if (pButton == m_pMaximizeButton)
        {
            pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
        }
        else if (pButton == m_pCloseButton)
        {
            pWindow->close();
        }
    }
}
*/

/*void myTitle::updateMaximize()
{
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        bool bMaximize = pWindow->isMaximized();
        if (bMaximize)
        {
            m_pMaximizeButton->setToolTip(tr("Restore"));
            m_pMaximizeButton->setProperty("maximizeProperty", "restore");
        }
        else
        {
            m_pMaximizeButton->setProperty("maximizeProperty", "maximize");
            m_pMaximizeButton->setToolTip(tr("Maximize"));
        }

        m_pMaximizeButton->setStyle(QApplication::style());
    }
}
*/

void myTitle::onClicked(){
}

void myTitle::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        mouse_press=true;
    }
    move_point=event->globalPos()-pos();
}


void myTitle::mouseReleaseEvent( QMouseEvent *)
{
  mouse_press = false;
}

void myTitle::mouseMoveEvent(QMouseEvent *event)
{
  //移动窗口
  if(mouse_press)
  {
    QPoint move_pos = event->globalPos();
    move(move_pos - move_point);
  }
}

void myTitle::show(){
    pParent->show();
}
