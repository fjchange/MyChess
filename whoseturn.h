#ifndef WHOSETURN_H
#define WHOSETURN_H
#include<QLabel>
#include<QWidget>

class WhoseTurn
{
private:
    QLabel*Turn1;
    QLabel*Turn2;
    QWidget*myWidget;
public:
    WhoseTurn(QWidget*myWid);
    void Show();
};

#endif // WHOSETURN_H
