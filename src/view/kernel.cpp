#include "kernel.h"

#include "ui_kernel.h"

namespace s21 {

Kernel::Kernel(QWidget *parent) : QDialog(parent), ui(new Ui::Kernel) {
  ui->setupUi(this);
  int size = ui->size->value();

  QObject::connect(ui->size, SIGNAL(valueChanged(int)), this, SLOT(size()));
  table(size);
}

Kernel::~Kernel() { delete ui; }

void Kernel::on_buttonBox_accepted() {
  QList<int> kernel;
  int size = ui->size->value();

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      kernel << qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(i, j))
                    ->value();
    }
  }
  emit getList(kernel);
}

void Kernel::on_clearTable_clicked() {
  int size = ui->size->value();
  table(size);
}

void Kernel::table(int size) {
  ui->tableWidget->clear();
  ui->tableWidget->setRowCount(size);
  ui->tableWidget->setColumnCount(size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      QSpinBox *tmp = new QSpinBox(ui->tableWidget);
      tmp->setRange(-255, 255);
      tmp->setValue(0);
      ui->tableWidget->setCellWidget(i, j, tmp);
    }
  }
}

void Kernel::size() {
  int size = ui->size->value();
  table(size);
}

}  // namespace s21
