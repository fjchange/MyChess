#ifndef MOVERECORD_H
#define MOVERECORD_H

#include<string>
#include<QWidget>
#include<QLabel>
#include<string>
#include<QObject>
#include<QString>
#include<QFont>
#include<win.h>
#include<QMessageBox>
class MoveRecord
{
//    Q_OBJECT
private:
    QString moveRecord;

public:
    Win* win;
    QLabel *moves;
    QMessageBox msgBox;
    MoveRecord(QWidget* myWidget){
        moves = new QLabel(myWidget);
        moves->setGeometry(1000,105,250,550);
        moves->setStyleSheet("QLabel {background-color: white;}");
        QFont font("Microsoft YaHei",15,75);
        moves->setFont(font);

       // QObject::connect(this,&MoveRecord::GameWin,win,&Win::show);
    }
    void addRecord(QString a );
/*signals:
    void GameWin();
*/

};

#endif // MOVERECORD_H
