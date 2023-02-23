#ifndef SETGAME_H
#define SETGAME_H

#include <QDialog>

namespace Ui {
  class setgame;
}

class setgame : public QDialog
{
  Q_OBJECT

public:
  explicit setgame(QWidget *parent = nullptr);
  ~setgame();
  int sizex;
  int sizey;
  int sizepx;
  int outxpx;
  int outypx;
  int startx;
  int starty;
  int time;

private slots:

  void on_mapsizex_textChanged(const QString &arg1);

  void on_mapsizey_textChanged(const QString &arg1);

  void on_genzipx_textChanged(const QString &arg1);

  void on_outx_textChanged(const QString &arg1);

  void on_outy_textChanged(const QString &arg1);

  void on_startx_textChanged(const QString &arg1);

  void on_starty_textChanged(const QString &arg1);

  void on_updatetime_textChanged(const QString &arg1);

  void on_pushButton_clicked();

signals:
  void click();
private:
  Ui::setgame *ui;
};

#endif // SETGAME_H
