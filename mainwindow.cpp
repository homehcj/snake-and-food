#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  _setgame =new setgame;
  _setctrl =new setctrl;
  ptimer = new QTimer;
  connect(ptimer, SIGNAL(timeout()), this, SLOT(game()));
  connect(_setgame,SIGNAL(click()),this,SLOT(newsetgame()));
  connect(_setctrl,SIGNAL(click()),this,SLOT(newsetmove()));
  //初始化数值
  move.up=_setctrl->up;
  move.down=_setctrl->down;
  move.rigth=_setctrl->rigth;
  move.left=_setctrl->left;
  zeropoint.x=_setgame->outxpx;
  zeropoint.y=_setgame->outypx;
  speed=_setgame->time;
  mapsize.x=_setgame->sizex;
  mapsize.y=_setgame->sizey;
  sizepx=_setgame->sizepx;
  snakestart.x=_setgame->startx;
  snakestart.y=_setgame->starty;

  this->setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);//禁用最大化
  this->setFixedSize(zeropoint.x*2+mapsize.x*sizepx,
                     zeropoint.y*2+mapsize.y*sizepx);
  gamemap =new map(mapsize.x,mapsize.y,snakestart.x,snakestart.y);
}

MainWindow::~MainWindow()
{
  delete ui;
  delete _setgame;
  delete ptimer;
  delete gamemap;
}

void MainWindow::paintEvent(QPaintEvent *)
{
  painter.begin(this);
  for(int i=0;i<=gamemap->pointmun;i++){
      switch (gamemap->mapmap[i].type) {
        case -1:
          pen.setColor(QColor(0,0,0,0));
          brush.setColor(QColor(0,0,0,255));
          brush.setStyle(Qt::DiagCrossPattern);
          painter.setBrush(brush);
          painter.setPen(pen);
          break;
        case 0:
          pen.setColor(QColor(0,0,0,0));
          brush.setColor(QColor(0,0,0,0));
          brush.setStyle(Qt::DiagCrossPattern);
          painter.setBrush(brush);
          painter.setPen(pen);
          break;
        case 1:
          pen.setColor(QColor(0,0,0,0));
          brush.setColor(QColor(0,255,0,255));
          brush.setStyle(Qt::SolidPattern);
          painter.setBrush(brush);
          painter.setPen(pen);
          break;
        case 2:
          pen.setColor(QColor(0,0,0,255));
          brush.setColor(QColor(255,0,0,255));
          brush.setStyle(Qt::Dense2Pattern);
          painter.setBrush(brush);
          painter.setPen(pen);
          break;
        }
      painter.drawRect(zeropoint.x+gamemap->mapmap[i].x*sizepx,zeropoint.y+gamemap->mapmap[i].y*sizepx,sizepx,sizepx);
    }
  painter.end();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
  if(event->key()==move.up&&(moveflg!=2||snake_eat_num==0)){
      moveflg=1;
      return;
    }
  if(event->key()==move.down&&(moveflg!=1||snake_eat_num==0)){
      moveflg=2;
      return;
    }
  if(event->key()==move.left&&(moveflg!=4||snake_eat_num==0)){
      moveflg=3;
      return;
    }
  if(event->key()==move.rigth&&(moveflg!=3||snake_eat_num==0)){
      moveflg=4;
      return;
    }
  if(event->key()==Qt::Key_Space){
      on_action_P_triggered();
      return;
    }
}

void MainWindow::newsetgame()
{
  delete gamemap;
  move.up=_setctrl->up;
  move.down=_setctrl->down;
  move.rigth=_setctrl->rigth;
  move.left=_setctrl->left;
  zeropoint.x=_setgame->outxpx;
  zeropoint.y=_setgame->outypx;
  speed=_setgame->time;
  mapsize.x=_setgame->sizex;
  mapsize.y=_setgame->sizey;
  sizepx=_setgame->sizepx;
  snakestart.x=_setgame->startx;
  snakestart.y=_setgame->starty;

  this->setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);//禁用最大化
  this->setFixedSize(zeropoint.x*2+mapsize.x*sizepx,
                     zeropoint.y*2+mapsize.y*sizepx);
  gamemap =new map(mapsize.x,mapsize.y,snakestart.x,snakestart.y);
  snake_move_num=0;
  snake_eat_num=0;
  moveflg=0;
}

void MainWindow::game()
{
  gamemap->clearmap();
  gamemap->movesnake(moveflg);
  snake_move_num++;
  switch (gamemap->checksnake()) {
    case -1:
      QMessageBox::warning(this,
                           "提示",
                           QString("你失败了，碰撞到边界\n你的蛇一共走了%1下，吃了%2个食物")
                           .arg(snake_move_num).arg(snake_eat_num));
      on_menu_game0_triggered();
      break;
    case 0:

      break;
    case 1:
      QMessageBox::warning(this,"提示",
                           QString("你失败了，碰撞到身体\n你的蛇一共走了%1下，吃了%2个食物")
                           .arg(snake_move_num).arg(snake_eat_num));
      on_menu_game0_triggered();
      break;
    case 2:
      snake_eat_num++;
      break;
    default:
      break;
    }
  ;
  this->update();
}

void MainWindow::on_menu_game_2_triggered()
{
    snake_move_num=0;
    snake_eat_num=0;
    moveflg=0;
    ptimer->start(speed);
}


void MainWindow::on_action_P_triggered()
{
  if(pauseflg==0){
      ptimer->stop();
      pauseflg=1;
      ui->action_P->setText("恢复游戏");
    }
  else {
      ptimer->start(speed);
      pauseflg=0;
      ui->action_P->setText("暂停游戏");
    }
}


void MainWindow::on_menu_game0_triggered()
{
    ptimer->stop();
    gamemap->newmap(mapsize.x,mapsize.y,snakestart.x,snakestart.y);
    moveflg=0;
}


void MainWindow::on_action_S_2_triggered()
{
    _setgame->show();
}


void MainWindow::on_action_O_triggered()
{
  _setctrl->show();
}

void MainWindow::newsetmove()
{
  move.up=_setctrl->up;
  move.down=_setctrl->down;
  move.rigth=_setctrl->rigth;
  move.left=_setctrl->left;
  _setctrl->close();
}

