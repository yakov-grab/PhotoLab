#ifndef KERNEL_H
#define KERNEL_H

#include <QDialog>

namespace Ui {
class Kernel;
}

namespace s21 {

class Kernel : public QDialog {
  Q_OBJECT

 public:
  Kernel(QWidget *parent = nullptr);  // explicit
  ~Kernel();

 signals:
  void getList(QList<int> kernel);

 private slots:
  void on_buttonBox_accepted();
  void on_clearTable_clicked();
  void size();

 private:
  Ui::Kernel *ui;
  void table(int size);
};

}  // namespace s21

#endif  // KERNEL_H
