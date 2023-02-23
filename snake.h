#ifndef SNAKE_H
#define SNAKE_H

class snake
{
private:
  struct body
  {
    int x;
    int y;
  };
  body* lastsnakebody;
  int lastbodylength;
  void savelastbody();
public:
  snake(int x,int y,int maxlength);
  ~snake();
  void upmove();
  void downmove();
  void left();
  void rigth();
  void eatfood();
  bool crashbody();
  int bodylength;
  body* snakebody;
};

#endif // SNAKE_H
