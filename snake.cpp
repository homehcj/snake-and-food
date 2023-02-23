#include "snake.h"

snake::snake(int x,int y,int maxlength)
{
  bodylength=1;
  lastbodylength=0;
  snakebody = new body[maxlength];
  lastsnakebody = new body[maxlength];
  snakebody[0].x=x;
  snakebody[0].y=y;
}

snake::~snake()
{
  delete lastsnakebody;
  delete snakebody;
}

void snake::savelastbody()
{
  lastbodylength=bodylength;
  for(int i=0;i<bodylength;i++){
      lastsnakebody[i].x=snakebody[i].x;
      lastsnakebody[i].y=snakebody[i].y;
    }
}

void snake::upmove()
{
  savelastbody();
  snakebody[0].x=snakebody[0].x;
  snakebody[0].y=snakebody[0].y-1;
  for(int i=0;i<lastbodylength-1;i++){
      snakebody[i+1].x=lastsnakebody[i].x;
      snakebody[i+1].y=lastsnakebody[i].y;
    }
}

void snake::downmove()
{
  savelastbody();
  snakebody[0].x=snakebody[0].x;
  snakebody[0].y=snakebody[0].y+1;
  for(int i=0;i<lastbodylength-1;i++){
      snakebody[i+1].x=lastsnakebody[i].x;
      snakebody[i+1].y=lastsnakebody[i].y;
    }
}

void snake::left()
{
  savelastbody();
  snakebody[0].x=snakebody[0].x-1;
  snakebody[0].y=snakebody[0].y;
  for(int i=0;i<lastbodylength-1;i++){
      snakebody[i+1].x=lastsnakebody[i].x;
      snakebody[i+1].y=lastsnakebody[i].y;
    }
}

void snake::rigth()
{
  savelastbody();
  snakebody[0].x=snakebody[0].x+1;
  snakebody[0].y=snakebody[0].y;
  for(int i=0;i<lastbodylength-1;i++){
      snakebody[i+1].x=lastsnakebody[i].x;
      snakebody[i+1].y=lastsnakebody[i].y;
    }
}

void snake::eatfood()//并发事件与移动事件同时存在
{
  snakebody[bodylength].x=lastsnakebody[lastbodylength-1].x;
  snakebody[bodylength].y=lastsnakebody[lastbodylength-1].y;
  bodylength++;
}

bool snake::crashbody()
{
  for(int i=1;i<bodylength;i++){
      if(snakebody[0].x==snakebody[i].x&&snakebody[0].y==snakebody[i].y){
          return true;
        }
    }
  return false;
}
