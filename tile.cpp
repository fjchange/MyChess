#include "tile.h"
#include "validation.h"
#include"chessboard.h"
#include"moverecord.h"
#include<QDebug>
#include<msg_box.h>

validation *valid = new validation();
extern int isAI;
extern int count,turn;
extern QWidget *myWidget;
extern Tile *click1;
extern Tile *tile[8][8];

QString action;
bool isWin=false;

int turnBefore=1;

void validate(Tile *temp,int c);
void disOrange();

/*
*tile is to get the action from mouse and show the information to the validation
* if we want to add ai
* we have to modify here
* add the parameter to repersent the  game module the player chose
* add an slot to get the information get by msg_box
*/
void transLatePlace(Tile* to,Tile*from){
    if(isWin){
           QMessageBox messageBox;
           if(isAI&&turn==1){

           messageBox.setWindowTitle("Game Over!");
           messageBox.setText("别泄气，再来一盘吧!");
           }
           else if(!isAI){
               messageBox.setWindowTitle("Game ends");
               if(turn==0)
                   messageBox.setText("Congratulation! Player 1 ! How Wonderful you play! ");
               else                     messageBox.setText("Congratulation! Player 2! How Wonderful you play! ");

           }
           else{
               messageBox.setWindowTitle("Congratulation!");
               messageBox.setText("Wow! How Smart you are! You beat the AI!");
           }
           messageBox.exec();
      }
    if(from->pieceName!='P')
    action+=(QChar)(from->pieceName);
    action+=(char)(8-from->row+'0');
    action+=(char)(from->col+'a');
    if(from->piece&&to->piece&&from->pieceColor!=to->pieceColor){
        action+='x';

        action+=(char)(to->pieceName);
    }
    else action+="--";
    action+=(char)(8-to->row+'0');
    action+=(char)(to->col+'a');
    if(turn==0){
        action+='\n';
       tile[0][0]->moverecord->addRecord(action);
       action.clear();

    }
    else action+='\t';
}

void Tile::mousePressEvent(QMouseEvent *event)
{
    validate(this,++count);
}
void Tile::display(char elem)
{
    this->pieceName=elem;
    if(this->pieceColor && this->piece)
    {
        switch(elem)
        {
            case 'P': this->setPixmap(QPixmap(":/images/res/pawn_white.svg"));
                      break;
            case 'R': this->setPixmap(QPixmap(":/images/res/rook_white.svg"));
                      break;
            case 'H': this->setPixmap(QPixmap(":/images/res/knight_white.svg"));
                      break;
            case 'K': this->setPixmap(QPixmap(":/images/res/king_white.svg"));
                      break;
            case 'Q': this->setPixmap(QPixmap(":/images/res/queen_white.svg"));
                      break;
            case 'B': this->setPixmap(QPixmap(":/images/res/bishop_white.svg"));
                      break;
        }
    }
    else if(this->piece)
    {
        switch(elem)
        {
        case 'P': this->setPixmap(QPixmap(":/images/res/pawn_black.svg"));
                  break;
        case 'R': this->setPixmap(QPixmap(":/images/res/rook_black.svg"));
                  break;
        case 'H': this->setPixmap(QPixmap(":/images/res/knight_black.svg"));
                  break;
        case 'K': this->setPixmap(QPixmap(":/images/res/king_black.svg"));
                  break;
        case 'Q': this->setPixmap(QPixmap(":/images/res/queen_black.svg"));
                  break;
        case 'B': this->setPixmap(QPixmap(":/images/res/bishop_black.svg"));
                  break;
        }
    }
    else this->clear();

}

/**
 * @brief validate
 * @param temp
 * @param c
 * modify here to add the parameter isAiModule
 * then change the action
 */


void validate(Tile *temp, int c)
{

    int retValue,i;
    if(c==1)
    {
        if(temp->piece && (temp->pieceColor==turn))
        {
            //Exp[max++]=temp->tileNum;//
            retValue=valid->chooser(temp);
            if(retValue)
            {

                click1= new Tile();
                temp->setStyleSheet("QLabel {background-color: green;}");
                click1=temp;
            }
            else
            {
                //temp->setStyleSheet("QLabel {background-color: red;}");//
                count=0;
            }
        }
        else
        {
            //qDebug()<<"Rascel, clicking anywhere";//
            count=0;
        }
    }

    else
    {
        if(temp->tileNum==click1->tileNum)
        {
            click1->tileDisplay();
            disOrange();
            max=0;
            count=0;
        }

        for(i=0;i<max;i++)
        {
            if(temp->tileNum==Exp[i])
            {
                //record the moves
                if(temp->piece&&temp->pieceColor!=turn&&temp->pieceName=='K'){
                    isWin=true;
                    qDebug()<<"Win!";
                }
                if(click1->pieceColor==0&&click1->pieceName=='P'&&temp->row==0){

                }
                transLatePlace(temp,click1);

                click1->piece=0;
                temp->piece=1;

                temp->pieceColor=click1->pieceColor;
                temp->pieceName=click1->pieceName;

                click1->display(click1->pieceName);
                temp->display(click1->pieceName);

                click1->tileDisplay();
                temp->tileDisplay();

                retValue=valid->check(click1);
                /*
                if(retValue)
                {
                    tile[wR][wC]->setStyleSheet("QLabel {background-color: red;}");
                }
                */

                disOrange();

                max=0;

                turn=(turn+1)%2;


                tile[0][0]->whoseturn->Show();


                count=0;
            }
            else
                count=1;
        }
    }
}

void Tile::tileDisplay()
{

    if(this->tileColor){
       // this->setPixmap(QPixmap(":/images/res/black tile"));
//        this->setScaledContents(true);
        this->setStyleSheet("QLabel {background-color: rgb(120, 120, 90);}:hover{background-color: rgb(170,85,127);}");
    }
    else{
//        this->setPixmap(QPixmap(":/images/res/white tile"));
 //       this->setScaledContents(true);
        this->setStyleSheet("QLabel {background-color: rgb(211, 211, 158);}:hover{background-color: rgb(170,95,127);}");
    }
}

void disOrange()
{
    int i;

    for(i=0;i<max;i++)
        tile[Exp[i]/8][Exp[i]%8]->tileDisplay();

}
