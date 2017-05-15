#ifndef TILE_H
#define TILE_H
#include <QLabel>
#include <QDebug>
#include<whoseturn.h>
#include<QObject>
#include<string>
#include<QString>
#include<moverecord.h>
#include<QMessageBox>
//TILE 主要负责实现棋盘
class Tile: public QLabel
{


public:

    //Fields
    int tileColor,piece,pieceColor,row,col,tileNum;
    char pieceName;
     WhoseTurn* whoseturn;
     MoveRecord*moverecord;
     QWidget*myWidget;
    //Constructors
    Tile(QWidget* pParent=0, Qt::WindowFlags f=0) : QLabel(pParent, f) {
       myWidget=pParent;
    };
/*    Tile(const QString& text, QWidget* pParent = 0, Qt::WindowFlags f = 0) : QLabel(text, pParent, f){
        whoseturn=new WhoseTurn(pParent);
    };
*/
    void buildTurn(){
        whoseturn=new WhoseTurn(myWidget);
         moverecord=new MoveRecord(myWidget);
    }

    //Methods
    void mousePressEvent(QMouseEvent *event);
    void display(char elem);
    void tileDisplay();

};

#endif // TILE_H
