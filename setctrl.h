#ifndef SETCTRL_H
#define SETCTRL_H

#include <QDialog>
#include <QEvent>
#include <QKeyEvent>
#include <QLineEdit>

namespace Ui {
  class setctrl;
}

class setctrl : public QDialog
{
  Q_OBJECT

public:
  explicit setctrl(QWidget *parent = nullptr);
  ~setctrl();
  int up;
  int down;
  int left;
  int rigth;
private slots:
  void on_pushButton_clicked();

signals:
  void click();

private:
  Ui::setctrl *ui;
  bool eventFilter(QObject *,QEvent *);//delete
  void keyPressEvent(QKeyEvent *);//delete
  void showkeyname(QLineEdit *,int);//delete
  int fixflg;
};

#endif // SETCTRL_H
