#include "border.h"
Border::Border()
{

}
 void Border::outline(QWidget *baseWidget, int xPos, int yPos, int Pos) {
     QLabel *outLabel = new QLabel(baseWidget);

    if(!Pos){
        outLabel->setGeometry(xPos,yPos,552,20);        //Horizontal Borders

    }
    else
        outLabel->setGeometry(xPos,yPos,20,512);        //Vertical Borders
        outLabel->setPixmap(QPixmap(":/images/res/white border"));
        outLabel->setScaledContents(true);
//   outLabel->setStyleSheet("QLabel { background-color :rgb(170, 170, 127); color : black; }");
}

