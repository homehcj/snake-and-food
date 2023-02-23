#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "setgame.h"
#include "setctrl.h"

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>

#include "map.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

private slots:
  void game();

  void on_menu_game_2_triggered();

  void on_action_P_triggered();

  void on_menu_game0_triggered();

  void on_action_S_2_triggered();

  void newsetgame();

  void on_action_O_triggered();

  void newsetmove();

private:
  Ui::MainWindow *ui;
  setgame* _setgame;
  setctrl* _setctrl;

  struct point
  {
    int x;
    int y;
  };
  struct moveway
  {
    int up;
    int down;
    int rigth;
    int left;
  };

  QPainter painter;
  QBrush brush;
  QPen pen;
  QTimer *ptimer;
  map *gamemap;
  int moveflg=0;
  int pauseflg=0;
  int map_point_mun;
  int snake_move_num=0;
  int snake_eat_num=0;

  void paintEvent(QPaintEvent *event);
  void keyPressEvent(QKeyEvent *event);

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  point mapsize;
  point snakestart;
  int sizepx;
  int speed;//蛇的速度
  point zeropoint;
  moveway move;
};
#endif // MAINWINDOW_H
