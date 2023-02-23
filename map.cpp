//储存地图状态
#include "map.h"
#include <QDebug>

map::map(int w, int h,int snakex,int snakey)
{
  width=w;
  heigth=h;
  pointmun=w*h;
  mapmap= new mappoint[width*heigth];
  int idx=0;
  for(int i=0;i<width;i++){
      for(int j=0;j<heigth;j++){
          mapmap[idx].x=i;
          mapmap[idx].y=j;
          if(i==0||j==0||i==width-1||j==heigth-1){
              mapmap[idx].type=-1;
            }
          else {
              mapmap[idx].type=0;
            }
          idx++;
        }
    }
  _snake= new snake(snakex,snakey,w*h);
  _food = new food();
  makefood();
}

map::~map()
{
  delete mapmap;
  delete _snake;
  delete _food;
}

void map::clearmap()
{
  int idx=0;
  for(int i=0;i<width;i++){
      for(int j=0;j<heigth;j++){
          mapmap[idx].x=i;
          mapmap[idx].y=j;
          if(i==0||j==0||i==width-1||j==heigth-1){
              mapmap[idx].type=-1;
            }
          else {
              mapmap[idx].type=0;
            }
          idx++;
        }
    }
  setfood();
}

void map::makefood()
{
  int tempx[pointmun];
  int tempy[pointmun];
  int templength=0;
  for(int i=0;i<=pointmun;i++){
      if(mapmap[i].type==0){
          tempx[templength]=mapmap[i].x;
          tempy[templength]=mapmap[i].y;
          templength++;
        }
    }
  QRandomGenerator rng(QTime::currentTime().msecsSinceStartOfDay());
  unsigned int arr[1];
  rng.fillRange(arr,1);
  int rangenumber=arr[0]%templength;
  _food->foodpoint.x=tempx[rangenumber];
  _food->foodpoint.y=tempy[rangenumber];
}

void map::setsnake()
{
  for(int i=0;i<_snake->bodylength;i++){
      mapmap[_snake->snakebody[i].x*heigth+_snake->snakebody[i].y].type=1;
    }
}

void map::setfood()
{
  //
    mapmap[_food->foodpoint.x*heigth+_food->foodpoint.y].type=2;
}

void map::movesnake(int flg)
{
  switch (flg) {
    case 1:
      _snake->upmove();
      break;
    case 2:
      _snake->downmove();
      break;
    case 3:
      _snake->left();
      break;
    case 4:
      _snake->rigth();

      break;
    default:
      break;
    }
  setsnake();
}

int map::checksnake()
{
  if(crashwall()){
      return -1;
    }
  if(_snake->crashbody()){
      return 1;
    }
  if(crashfood()){
      makefood();
      return 2;
    }
  return 0;
}

void map::newmap(int w, int h, int snakex, int snakey)
{
  delete mapmap;
  delete _snake;
  delete _food;
  width=w;
  heigth=h;
  pointmun=w*h;
  mapmap= new mappoint[width*heigth];
  int idx=0;
  for(int i=0;i<width;i++){
      for(int j=0;j<heigth;j++){
          mapmap[idx].x=i;
          mapmap[idx].y=j;
          if(i==0||j==0||i==width-1||j==heigth-1){
              mapmap[idx].type=-1;
            }
          else {
              mapmap[idx].type=0;
            }
          idx++;
        }
    }
  _snake= new snake(snakex,snakey,w*h);
  _food = new food();
  makefood();
}

bool map::crashfood()
{
  if(_snake->snakebody->x==_food->foodpoint.x&&_snake->snakebody->y==_food->foodpoint.y){
      _snake->eatfood();
      return true;
    }
  return false;

}

bool map::crashwall()
{
  if(_snake->snakebody[0].x>=width-1||_snake->snakebody[0].x<=0||_snake->snakebody[0].y>=heigth-1||_snake->snakebody[0].y<=0){
      return true;
    }
  return false;
}
