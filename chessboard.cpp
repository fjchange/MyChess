#include "chessboard.h"

extern int count,turn;
extern int wR,wC,bR,bC;

ChessBoard::ChessBoard(QWidget* myWid)
{
    this->myWidget=myWid;
    whoseturn=new WhoseTurn(myWidget);
    accessories();
}
void ChessBoard::accessories(){
    QLabel *player2 = new QLabel(myWidget);
    QLabel *name2 = new QLabel("Player 2", myWidget);
    QLabel *time2 = new QLabel("00:00:00", myWidget);
    QLabel *player1 = new QLabel(myWidget);
    QLabel *name1 = new QLabel("Player 1", myWidget);
    QLabel *time1 = new QLabel("00:00:00", myWidget);



    name1->setGeometry(125,610,80,20);
    time1->setGeometry(120,635,80,20);
    player1->setGeometry(100,500,100,100);

    player1->setPixmap(QPixmap(":/images/profile"));

    name2->setGeometry(125,210,80,20);
    time2->setGeometry(120,235,80,20);
    player2->setGeometry(100,100,100,100);
    player2->setPixmap(QPixmap(":/images/profile"));
}
void ChessBoard::chessBoard(Tile*tile[8][8])
{
    int i,j,k=0,hor,ver;
    Border *border[4]={ NULL };

    //borderDisplay
    {
    border[0]->outline(myWidget,330,105,0);
    border[1]->outline(myWidget,330,637,0);
    border[2]->outline(myWidget,330,125,1);
    border[2]->outline(myWidget,862,125,1);
    }

    //Create 64 tiles (allocating memories to the objects of Tile class)
    ver=125;
    for(i=0;i<8;i++)
    {
        hor=350;
        for(j=0;j<8;j++)
        {
            tile[i][j] = new Tile(myWidget);
            tile[i][j]->tileColor=(i+j)%2;
            tile[i][j]->piece=0;
            tile[i][j]->row=i;
            tile[i][j]->col=j;
            tile[i][j]->tileNum=k++;
            tile[i][j]->tileDisplay();
            tile[i][j]->setGeometry(hor,ver,64,64);

            hor+=64;
            if(!i&&!j){
                tile[i][j]->buildTurn();
                tile[i][j]->whoseturn->Show();

            }
        }
        ver+=64;
    }

    //white pawns
    for(j=0;j<8;j++)
    {
        tile[1][j]->piece=1;
        tile[1][j]->pieceColor=0;
        tile[1][j]->display('P');
    }

    //black pawns
    for(j=0;j<8;j++)
    {
        tile[6][j]->piece=1;
        tile[6][j]->pieceColor=1;
        tile[6][j]->display('P');
    }

    //white and black remaining elements
    for(j=0;j<8;j++)
    {
        tile[0][j]->piece=1;
        tile[0][j]->pieceColor=0;
        tile[7][j]->piece=1;
        tile[7][j]->pieceColor=1;
    }

    {
    tile[0][0]->display('R');
    tile[0][1]->display('H');
    tile[0][2]->display('B');
    tile[0][3]->display('Q');
    tile[0][4]->display('K');
    tile[0][5]->display('B');
    tile[0][6]->display('H');
    tile[0][7]->display('R');
    }


    {
    tile[7][0]->display('R');
    tile[7][1]->display('H');
    tile[7][2]->display('B');
    tile[7][3]->display('Q');
    tile[7][4]->display('K');
    tile[7][5]->display('B');
    tile[7][6]->display('H');
    tile[7][7]->display('R');
    }

    wR=7;
    wC=4;

    bR=0;
    bC=4;

}


void ChessBoard::show(){
    myWidget->show();
}
