#ifndef INTERFACE_H
#define INTERFACE_H

#include <QDialog>
#include <functional>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class Interface;
}
QT_END_NAMESPACE

namespace s21 {

class Interface : public QDialog {
  Q_OBJECT

 public:
  explicit Interface(QWidget *parent = nullptr,
                     std::function<void(char, int)> determinant = nullptr,
                     std::function<void(int)> reply = nullptr);  // explicit
  ~Interface();

 private slots:
  void brightnessS();
  void contrastS();
  void saturationS();
  void hueS();
  void lightnessS();
  void brightnessV();
  void contrastV();
  void saturationV();
  void hueV();
  void lightnessV();
  void on_ok_clicked();
  void on_cancel_clicked();

 private:
  Ui::Interface *ui;
  std::function<void(char, int)> determinant;
  std::function<void(int)> reply;
};

}  // namespace s21

#endif  // INTERFACE_H
