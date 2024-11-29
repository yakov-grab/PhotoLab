#include "interface.h"

#include "./ui_interface.h"

namespace s21 {

Interface::Interface(QWidget *parent,
                     std::function<void(char, int)> determinant,
                     std::function<void(int)> reply)
    : QDialog(parent),
      ui(new Ui::Interface),
      determinant(determinant),
      reply(reply) {
  ui->setupUi(this);

  QObject::connect(ui->brightSlider, SIGNAL(valueChanged(int)), this,
                   SLOT(brightnessS()));
  QObject::connect(ui->contrSlider, SIGNAL(valueChanged(int)), this,
                   SLOT(contrastS()));
  QObject::connect(ui->saturSlider, SIGNAL(valueChanged(int)), this,
                   SLOT(saturationS()));
  QObject::connect(ui->hueSlider, SIGNAL(valueChanged(int)), this,
                   SLOT(hueS()));
  QObject::connect(ui->lightSlider, SIGNAL(valueChanged(int)), this,
                   SLOT(lightnessS()));

  QObject::connect(ui->brightVal, SIGNAL(valueChanged(int)), this,
                   SLOT(brightnessV()));
  QObject::connect(ui->contrVal, SIGNAL(valueChanged(int)), this,
                   SLOT(contrastV()));
  QObject::connect(ui->saturVal, SIGNAL(valueChanged(int)), this,
                   SLOT(saturationV()));
  QObject::connect(ui->hueVal, SIGNAL(valueChanged(int)), this, SLOT(hueV()));
  QObject::connect(ui->lightVal, SIGNAL(valueChanged(int)), this,
                   SLOT(lightnessV()));
}

Interface::~Interface() { delete ui; }

void Interface::brightnessS() {
  ui->brightVal->setValue(ui->brightSlider->value());
  determinant('B', ui->brightVal->value());
}
void Interface::contrastS() {
  ui->contrVal->setValue(ui->contrSlider->value());
  determinant('C', ui->contrVal->value());
}
void Interface::saturationS() {
  ui->saturVal->setValue(ui->saturSlider->value());
  determinant('S', ui->saturVal->value());
}
void Interface::hueS() {
  ui->hueVal->setValue(ui->hueSlider->value());
  determinant('H', ui->hueVal->value());
}
void Interface::lightnessS() {
  ui->lightVal->setValue(ui->lightSlider->value());
  determinant('L', ui->lightVal->value());
}

//////////////////////////////////////////////////////
void Interface::brightnessV() {
  ui->brightSlider->setValue(ui->brightVal->value());
  determinant('B', ui->brightVal->value());
}
void Interface::contrastV() {
  ui->contrSlider->setValue(ui->contrVal->value());
  determinant('C', ui->contrVal->value());
}
void Interface::saturationV() {
  ui->saturSlider->setValue(ui->saturVal->value());
  determinant('S', ui->saturVal->value());
}
void Interface::hueV() {
  ui->hueSlider->setValue(ui->hueVal->value());
  determinant('H', ui->hueVal->value());
}
void Interface::lightnessV() {
  ui->lightSlider->setValue(ui->lightVal->value());
  determinant('L', ui->lightVal->value());
}

void Interface::on_ok_clicked() {
  reply(1);
  close();
}
void Interface::on_cancel_clicked() {
  reply(0);
  close();
}

}  // namespace s21
