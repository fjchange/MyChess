#ifndef MYTITLE_H
#define MYTITLE_H

#include<QLabel>
#include<QWidget>
#include<QPushButton>
#include<QTimer>
#include<QMouseEvent>
#include<QPoint>

enum ButtonType{
    MIN_BUTTON=0,
    MIN_MAX_BUTTON,
    ONLY_CLOSE_BUTTON
};

class myTitle:public QWidget
{
    Q_OBJECT
public:
    QWidget*pParent;
    QPoint move_point;
    bool mouse_press;
    explicit myTitle(QWidget *parent=0);
    ~myTitle(){};
protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
 //   virtual void mousePressEvent(QMouseEvent *event);
//    virtual bool eventFilter(QObject *watched, QEvent *event);
private slots:
    void onClicked();
private:
    void mousePressEvent( QMouseEvent * event );
    void mouseReleaseEvent( QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *event);

//    void UpdateMaxmize();
public:
    QLabel *m_pIconLabel;
    QLabel*m_pTitleLabel;
    QPushButton*m_pCloseButton;
    QPushButton*m_pMaximizeButton;
    QPushButton*m_pMinimizeButton;
    void show();
};

#endif // MYTITLE_H
