#include "msg_box.h"

extern int isAI;

MsgBox::MsgBox(QWidget *parent)
 : QDialog(parent)
{
  this->resize(320, 160);
  //获取主界面的宽度
  int width = this->width();
  int height = this->height();
  //初始化为未按下鼠标左键
  mouse_press = false;
  //设置标题栏隐藏
  this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

  close_button = new QPushButton(QPixmap(":/images/close"),tr(""),this);
  close_button->setGeometry(width-30, 0,30, 30);

  //设置标题
  title_label = new QLabel(this);
  title_label->setObjectName(QString::fromUtf8("labelOne"));


  QFont font = title_label->font();
  font.setBold(true);
  title_label->setFont(font);
  title_label->setGeometry(0, 0, width, 30);

  title_label->setPixmap(QPixmap(":/images/res/white tile.jpg"));
  title_label->setScaledContents(true);

  //设置提示图片
  msg_label = new QLabel(this);
  msg_label->setGeometry(20, 50, 36, 36);
  msg_label->setScaledContents(true);
  //设置提示信息，让QLabel能够自动判断并换行显示：
  ask_label = new QLabel(this);
  ask_label->setGeometry(65, 60, width-100, 25*2);
  ask_label->setWordWrap(true);
  ask_label->setAlignment(Qt::AlignTop);

  check_box = new QCheckBox(this);
  check_box->setGeometry(10, height - 35, 160, 25);
  check_box->setHidden(true);
  cancel_button = new QPushButton(this);
  cancel_button->resize(120, 25);
  cancel_button->move(width - cancel_button->width() - 10, height - 35);
  ok_button = new QPushButton(this);
  ok_button->resize(120, 25);
  ok_button->move(width - ok_button->width() - cancel_button->width() - 20, height - 35);
  check_box->setStyleSheet("background:transparent;");
  ok_button->setObjectName(QString::fromUtf8("pushButtonTwo"));
  cancel_button->setObjectName(QString::fromUtf8("pushButtonTwo"));

  QObject::connect(ok_button, SIGNAL(clicked()), this, SLOT(okOperate()));
  QObject::connect(close_button, SIGNAL(clicked()), this, SLOT(cancelOperate()));
  QObject::connect(cancel_button, SIGNAL(clicked()), this, SLOT(cancelOperate()));

  this->translateLanguage();
}
void MsgBox::translateLanguage(){
    close_button->setToolTip(tr("close"));
    check_box->setText(tr("remember"));
    ok_button->setText(tr("Play with AI!"));
    cancel_button->setText(tr("Play with friend!"));
}
void MsgBox::setInfo(QString title_info, QString info, QPixmap pixmap, bool is_check_hidden, bool is_ok_hidden){
    title_label->setText(title_info);
    ask_label->setText(info);
    msg_label->setPixmap(pixmap);
    if(is_check_hidden){
        check_box->hide();
    }
    if(is_ok_hidden){
        ok_button->hide();
    }
}


void MsgBox::mousePressEvent( QMouseEvent * event )
{
  //只能是鼠标左键移动和改变大小
  if(event->button() == Qt::LeftButton)
  {
    mouse_press = true;
  }
  //窗口移动距离
  move_point = event->globalPos() - pos();
}
void MsgBox::mouseReleaseEvent( QMouseEvent *)
{
  mouse_press = false;
}
void MsgBox::mouseMoveEvent(QMouseEvent *event)
{
  //移动窗口
  if(mouse_press)
  {
    QPoint move_pos = event->globalPos();
    move(move_pos - move_point);
  }
}

void MsgBox::okOperate()
{
    /*
  bool is_hidden = check_box->isHidden();
  if(!is_hidden)
  {
    bool is_checked = check_box->isChecked();
    emit msgChecked(is_checked, true);
  }*/
   isAI=1;
   this->close();
 // this->exec();
}
void MsgBox::closeOperate(){
    if(isAI<0){

    }
    else
        this->close();
    //this->exec();
}

void MsgBox::cancelOperate()
{/*
  bool is_check_hidden = check_box->isHidden();
  bool is_ok_hidden = ok_button->isHidden();
  if(!is_check_hidden)
  {
    bool is_checked = check_box->isChecked();
    if(!is_ok_hidden)
    {
      emit msgChecked(is_checked, false);
    }
   else
   {
     emit okMessageHidden(is_checked);
   }
  }*/
  isAI=0;
  this->close();
  //this->exec();
}
