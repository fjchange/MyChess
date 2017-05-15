#include "win.h"

extern int g_nActScreenX,g_nActScreenY;
Win::Win()
{
    myWidget=new QWidget();
    myWidget->setGeometry(0.25*g_nActScreenX,0.25*g_nActScreenY,0.5*g_nActScreenX,0.5*g_nActScreenY);

    title=new QLabel(myWidget);
    message=new QLabel(myWidget);
    imageLabel=new QLabel(myWidget);
    ok=new QPushButton(myWidget);
    close=new QPushButton(myWidget);

    title->setGeometry(0.25*g_nActScreenX,0.25*g_nActScreenY,0.5*g_nActScreenX,20);
    title->setText("Congratulation!");


}
