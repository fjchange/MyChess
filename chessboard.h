#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include"tile.h"
#include<QLabel>
#include<QWidget>
#include"border.h"
#include<QPixmap>
#include<QObject>
#include"whoseturn.h"
class ChessBoard
{
//Q_OBJECT
private:
   QWidget* myWidget;
   WhoseTurn* whoseturn;
    QLabel* GiveIn,*Save,*Deuce;

public:
    ChessBoard(QWidget* myWid);
    void  accessories();
    void chessBoard(Tile*tile[8][8]);
    void show();
/*
signals:
    void giveup();
    void save();
    void deuce();
    */
};

#endif // CHESSBOARD_H
