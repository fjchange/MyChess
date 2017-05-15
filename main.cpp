#include <QApplication>
#include "mainwindow.h"
#include "tile.h"
#include"msg_box.h"
#include"border.h"
#include<QString>
#include<QWidget>
#include<QObject>
#include"chessboard.h"
#include"whoseturn.h"
#include"moverecord.h"
#include<QDesktopWidget>
#include<mytitlebar.h>

int count=0,turn=1,Exp[60],max=0;
int isAI=-1;
int wR,wC,bR,bC;
int g_nActScreenX,g_nActScreenY;
Tile *click1;

Tile *tile[8][8] = { { NULL } };

int main(int argc, char *argv[])
{
    QDesktopWidget* desktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = desktopWidget->availableGeometry();
    g_nActScreenX = deskRect.width();
    g_nActScreenY = deskRect.height();
    QApplication a(argc, argv);

    QWidget *myWidget = new QWidget();
    myWidget->setGeometry(5,5,1024,768);
    ChessBoard chessboard(myWidget);
    chessboard.chessBoard(tile);

    QWidget *Widget =new QWidget();
    Widget->setGeometry(50,50,200,200);

    MsgBox *msg_box=new MsgBox(Widget);
    msg_box->setInfo(QString ("Just Play the Game!"),QString("选择游戏类型"),
        QPixmap(":/images/res/exp.png"),true,false);

     QWidget*theWidget=new QWidget();
     theWidget->setGeometry(20,20,1024,586);
     myTitle mytitle(theWidget);
     mytitle.show();

    msg_box->exec();

    chessboard.show();

    return a.exec();
}

