#ifndef WIN_H
#define WIN_H

#include<QPushButton>
#include<QWidget>
#include<QDialog>
#include<QLabel>
#include<QFont>
#include<QPixmap>
#include<QPoint>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QMessageBox>
#include<QObject>
class Win
{
//    Q_OBJECT
public:
    QWidget*myWidget;
    QLabel*title;
    QPushButton*close,*ok;
    QLabel*message;
    QLabel*imageLabel;

    Win();
/*public slots:
    void show();
    */
};

#endif // WIN_H
