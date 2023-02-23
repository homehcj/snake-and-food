#ifndef FOOD_H
#define FOOD_H

#include <QTime>
#include <QRandomGenerator>

class food
{
private:
  struct point
  {
    int x;
    int y;
  };
public:
  food();
  ~food();
  point foodpoint;

};

#endif // FOOD_H
