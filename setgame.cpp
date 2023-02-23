#include "setgame.h"
#include "ui_setgame.h"

setgame::setgame(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::setgame)
{
  ui->setupUi(this);
  this->setFixedSize(this->width(),this->height());
  sizex=40;
  sizey=40;
  sizepx=10;
  outxpx=50;
  outypx=50;
  startx=5;
  starty=5;
  time=100;

  ui->mapsizex->setText(QString::number(sizex));
  ui->mapsizey->setText(QString::number(sizey));
  ui->genzipx->setText(QString::number(sizepx));
  ui->outx->setText(QString::number(outxpx));
  ui->outy->setText(QString::number(outypx));
  ui->startx->setText(QString::number(startx));
  ui->starty->setText(QString::number(starty));
  ui->updatetime->setText(QString::number(time));
}

setgame::~setgame()
{
  delete ui;
}


void setgame::on_mapsizex_textChanged(const QString &arg1)
{
    sizex=arg1.toInt();
}


void setgame::on_mapsizey_textChanged(const QString &arg1)
{
    sizey=arg1.toInt();
}


void setgame::on_genzipx_textChanged(const QString &arg1)
{
    sizepx=arg1.toInt();
}


void setgame::on_outx_textChanged(const QString &arg1)
{
    outxpx=arg1.toInt();
}


void setgame::on_outy_textChanged(const QString &arg1)
{
    outypx=arg1.toInt();
}


void setgame::on_startx_textChanged(const QString &arg1)
{
    startx=arg1.toInt();
}


void setgame::on_starty_textChanged(const QString &arg1)
{
    starty=arg1.toInt();
}


void setgame::on_updatetime_textChanged(const QString &arg1)
{
    time=arg1.toInt();
}

void setgame::on_pushButton_clicked()
{
    click();
    this->close();
}

