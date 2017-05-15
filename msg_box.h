#ifndef MSG_BOX_H
#define MSG_BOX_H
#include<QObject>
#include<QDialog>
#include<QWidget>
#include<QString>
#include<QWidget>
#include<QMouseEvent>
#include<QPixmap>
#include<QPushButton>
#include<QLabel>
#include<QCheckBox>
#include<QPoint>
#include<QPaintEvent>
#include<QObject>

class MsgBox:public QDialog{

    Q_OBJECT

private:
    bool mouse_press;
    QPushButton* close_button,*cancel_button,*ok_button;
    QLabel* title_label;
    QLabel*msg_label;
    QLabel*ask_label;
    QCheckBox *check_box;
    QPoint move_point;
private    slots:
    void okOperate();
    void cancelOperate();
    void closeOperate();
public:
    MsgBox(QWidget *parent);
    void setInfo(QString title_info, QString info, QPixmap pixmap, bool is_check_hidden, bool is_ok_hidden);
    void translateLanguage();
    void mousePressEvent( QMouseEvent * event );
    void mouseReleaseEvent( QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *event);

    void setPixmap(QPixmap pixmap);
signals:
    void msgChecked(const bool &isChecked,const bool& is );
    void okMessageHidden(const bool &is);

    void aiChosen(const bool &is);
    void closeChosen(const bool &is);
};

#endif // MSG_BOX_H
