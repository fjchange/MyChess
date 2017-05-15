#ifndef BOARDER_H
#define BOARDER_H
#include<QLabel>
#include<QWidget>

class Border
{

public:
    Border();
    Border(QWidget* parent);
    void outline(QWidget *baseWidget, int xPos, int yPos, int Pos);
};

#endif // BOARDER_H
