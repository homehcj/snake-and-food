#include "setctrl.h"
#include "ui_setctrl.h"

setctrl::setctrl(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::setctrl)
{
  ui->setupUi(this);
  ui->up->installEventFilter(this);
  ui->down->installEventFilter(this);
  ui->left->installEventFilter(this);
  ui->rigth->installEventFilter(this);
  ui->up->setText("上键");
  ui->down->setText("下键");
  ui->left->setText("左键");
  ui->rigth->setText("右键");
  up=Qt::Key_Up;
  down=Qt::Key_Down;
  left=Qt::Key_Left;
  rigth=Qt::Key_Right;
}

setctrl::~setctrl()
{
  delete ui;
}

void setctrl::on_pushButton_clicked()
{
  click();
}

//delete
bool setctrl::eventFilter(QObject *object, QEvent *event)
{
  if(object==ui->up){
      QString text=ui->up->text();
      ui->up->setFocusPolicy(Qt::ClickFocus);
      if(event->type()==QEvent::FocusIn){
          fixflg=0;
        }
      if(event->type()==QEvent::FocusOut&&fixflg==0){
          ui->up->setText(text);
        }
    }
  if(object==ui->down){
      QString text=ui->down->text();
      ui->down->setFocusPolicy(Qt::ClickFocus);
      if(event->type()==QEvent::FocusIn){
              fixflg=0;
        }
      if(event->type()==QEvent::FocusOut&&fixflg==0){
          ui->down->setText(text);
        }
    }
  if(object==ui->left){
      QString text=ui->left->text();
      ui->left->setFocusPolicy(Qt::ClickFocus);
      if(event->type()==QEvent::FocusIn){
              fixflg=0;
        }
      if(event->type()==QEvent::FocusOut&&fixflg==0){
          ui->left->setText(text);
        }
    }
  if(object==ui->rigth){
      QString text=ui->rigth->text();
      ui->rigth->setFocusPolicy(Qt::ClickFocus);
      if(event->type()==QEvent::FocusIn){
              fixflg=0;
        }
      if(event->type()==QEvent::FocusOut&&fixflg==0){
          ui->rigth->setText(text);
        }
    }
  return false;
}

//delete
void setctrl::keyPressEvent(QKeyEvent *event)
{
    if(this->focusWidget()==ui->up){
        fixflg=1;
        showkeyname(ui->up,event->key());
        up=event->key();
        this->setFocus();
      }
    if(this->focusWidget()==ui->down){
        fixflg=1;
        showkeyname(ui->down,event->key());
        down=event->key();
        this->setFocus();
      }
    if(this->focusWidget()==ui->left){
        fixflg=1;
        showkeyname(ui->left,event->key());
        left=event->key();
        this->setFocus();
      }
    if(this->focusWidget()==ui->rigth){
        fixflg=1;
        showkeyname(ui->rigth,event->key());
        rigth=event->key();
        this->setFocus();
      }
}

//delete
void setctrl::showkeyname(QLineEdit *plineedit, int key)
{
  QString text=" ";
  switch (key) {
    case Qt::Key_Up:
      text="上键";
      plineedit->setText(text);
      break;
    case Qt::Key_Down:
      text="下键";
      plineedit->setText(text);
      break;
    case Qt::Key_Right:
      text="左键";
      plineedit->setText(text);
      break;
    case Qt::Key_Left:
      text="右键";
      plineedit->setText(text);
      break;
    default:
      break;
    }
}
