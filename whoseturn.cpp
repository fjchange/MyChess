#include "whoseturn.h"
#include<iostream>
using namespace std;
extern int turn;
WhoseTurn::WhoseTurn(QWidget*myWid)
{
    myWidget=myWid;
    Turn1=new QLabel(myWidget);
    Turn2=new QLabel(myWidget);
    Turn1->setGeometry(30,500,64,83);
    Turn2->setGeometry(30,100,64,83);
    Turn1->setPixmap(QPixmap(":/images/turn1"));
    Turn1->setFixedSize(48,48);
    Turn2->setPixmap(QPixmap(":/images/turn2"));
    Turn2->setFixedSize(48,48);
    Turn2->setVisible(false);
    Turn1->setVisible(false);
}
void WhoseTurn::Show(){
    bool isTurn1=Turn1->isVisible();
    bool isTurn2=Turn2->isVisible();
    if(!isTurn1){
        Turn1->setVisible(true);
        Turn2->setVisible(false);
    }
    else{
        Turn1->setVisible(false);
        Turn2->setVisible(true);
    }
}
