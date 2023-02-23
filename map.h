#ifndef MAP_H
#define MAP_H

#include "snake.h"
#include "food.h"

class map
{

private:
  struct mappoint //记录地图上每个点
  {
       int x;
       int y;
       int type; //0：空；1：蛇；2：食物；-1:墙
  };
  int heigth;
  int width;
  snake *_snake;
  food *_food;
  bool crashfood();
  bool crashwall();
  void makefood();
  void setsnake();
  void setfood();
public:
  map(int w,int h,int snakex,int snakey);
  ~map();
  void clearmap();
  void movesnake(int flg);
  int checksnake();
  void newmap(int w,int h,int snakex,int snakey);
  mappoint* mapmap; //地图
  int pointmun;//点个数
};

#endif // MAP_H
