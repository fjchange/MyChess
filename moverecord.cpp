#include "moverecord.h"



void MoveRecord::addRecord(QString a){
    if(a!="!"){
    moveRecord+=a;}
    else{ moveRecord+="The Game is End!";
        //emit GameWin();
    }
    moves->setText(moveRecord);
}
