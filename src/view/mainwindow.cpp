#include "mainwindow.h"

#include "./ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QObject::connect(&kernel, &Kernel::getList, this, &MainWindow::kernelList);
  QObject::connect(ui->brightness, SIGNAL(valueChanged(int)), this,
                   SLOT(brightness()));
  QObject::connect(ui->contrast, SIGNAL(valueChanged(int)), this,
                   SLOT(contrast()));
  QObject::connect(ui->saturation, SIGNAL(valueChanged(int)), this,
                   SLOT(saturation()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::ShowStartImage() {
  ui->img->setPixmap(QPixmap::fromImage(imgStart));
  startImg = true;
}

void MainWindow::ShowFilteredImage() {
  ui->img->setPixmap(QPixmap::fromImage(imgFilter));
  startImg = false;
}

void MainWindow::on_loadImg_clicked() {
  QString path = QFileDialog::getOpenFileName(
      this, tr("Choose File"), QDir::currentPath(), tr("bmp(*.bmp)"));
  int width = ui->img->width();
  int height = ui->img->height();
  imgStart = imgFilter =
      QImage(path).scaled(width, height, Qt::KeepAspectRatio);
  ui->img_2->setPixmap(QPixmap::fromImage(imgStart));
  ShowStartImage();
}

void MainWindow::on_saveImg_clicked() {
  QString filePath = QFileDialog::getSaveFileName(this, "Save Image");
  if (filePath.length()) {
    imgFilter.save(filePath + ".bmp", "BMP");
  }
}

void MainWindow::on_clearImg_clicked() {
  imgFilter = imgStart;
  ShowStartImage();
}

void MainWindow::on_grayscale_clicked() {
  if (startImg) {
    imgFilter = controller.grayscale(imgStart);
  } else {
    imgFilter = controller.grayscale(imgFilter);
  }
  ShowFilteredImage();
}
void MainWindow::on_negative_clicked() {
  if (startImg) {
    imgFilter = controller.negative(imgStart);
  } else {
    imgFilter = controller.negative(imgFilter);
  }
  ShowFilteredImage();
}
void MainWindow::on_toning_clicked() {
  if (startImg) {
    imgFilter = controller.toning(imgStart);
  } else {
    imgFilter = controller.toning(imgFilter);
  }
  ShowFilteredImage();
}
void MainWindow::on_emboss_clicked() {
  if (startImg) {
    imgFilter = controller.emboss(imgStart);
  } else {
    imgFilter = controller.emboss(imgFilter);
  }
  ShowFilteredImage();
}
void MainWindow::on_sharpen_clicked() {
  if (startImg) {
    imgFilter = controller.sharpen(imgStart);
  } else {
    imgFilter = controller.sharpen(imgFilter);
  }
  ShowFilteredImage();
}
void MainWindow::on_boxBlur_clicked() {
  if (startImg) {
    imgFilter = controller.boxBlur(imgStart);
  } else {
    imgFilter = controller.boxBlur(imgFilter);
  }
  ShowFilteredImage();
}
void MainWindow::on_gaussianBlur_clicked() {
  if (startImg) {
    imgFilter = controller.gaussianBlur(imgStart);
  } else {
    imgFilter = controller.gaussianBlur(imgFilter);
  }
  ShowFilteredImage();
}
void MainWindow::on_laplacian_clicked() {
  if (startImg) {
    imgFilter = controller.laplacian(imgStart);
  } else {
    imgFilter = controller.laplacian(imgFilter);
  }
  ShowFilteredImage();
}

void MainWindow::on_sobel_clicked() {
  if (startImg) {
    imgFilter = controller.sobel(imgStart);
  } else {
    imgFilter = controller.sobel(imgFilter);
  }
  ShowFilteredImage();
}

void MainWindow::on_sobelLeft_clicked() {
  if (startImg) {
    imgFilter = controller.sobelLeft(imgStart);
  } else {
    imgFilter = controller.sobelLeft(imgFilter);
  }
  ShowFilteredImage();
}
void MainWindow::on_sobelRight_clicked() {
  if (startImg) {
    imgFilter = controller.sobelRight(imgStart);
  } else {
    imgFilter = controller.sobelRight(imgFilter);
  }
  ShowFilteredImage();
}

void MainWindow::on_kernel_clicked() { kernel.exec(); }

void MainWindow::kernelList(QList<int> kernel) {
  if (startImg) {
    imgFilter = controller.kernel(imgStart, kernel);
  } else {
    imgFilter = controller.kernel(imgFilter, kernel);
  }
  ShowFilteredImage();
}

void MainWindow::brightness() {
  if (startImg) {
    imgTmp = controller.brightness(imgStart, ui->brightness->value());
  } else {
    imgTmp = controller.brightness(imgFilter, ui->brightness->value());
  }
  ui->img->setPixmap(QPixmap::fromImage(imgTmp));
}

void MainWindow::contrast() {
  if (startImg) {
    imgTmp = controller.contrast(imgStart, ui->contrast->value());
  } else {
    imgTmp = controller.contrast(imgFilter, ui->contrast->value());
  }
  ui->img->setPixmap(QPixmap::fromImage(imgTmp));
}

void MainWindow::saturation() {
  int type = 0;
  if (ui->HSV) type = 1;
  if (startImg) {
    imgTmp = controller.saturation(imgStart, ui->saturation->value(), type);
  } else {
    imgTmp = controller.saturation(imgFilter, ui->saturation->value(), type);
  }
  ui->img->setPixmap(QPixmap::fromImage(imgTmp));
}

void MainWindow::hue(int val) {
  int type = 0;
  if (ui->HSV) type = 1;
  if (startImg) {
    imgTmp = controller.saturation(imgStart, val, type);
  } else {
    imgTmp = controller.saturation(imgFilter, val, type);
  }
  ui->img->setPixmap(QPixmap::fromImage(imgTmp));
}

void MainWindow::on_colorInter_clicked() {
  if (!startImg)
    imgTmp = imgFilter;
  else
    imgTmp = imgStart;
  Interface interface(
      this,
      std::bind(&MainWindow::imgChange, this, std::placeholders::_1,
                std::placeholders::_2),
      std::bind(&MainWindow::colorSave, this, std::placeholders::_1));
  interface.exec();
}

void MainWindow::imgChange(char ch, int val) {
  int type = 0;
  if (ui->HSV) type = 1;

  if (ch == 'B')
    imgTmp = controller.brightness(imgFilter, val);
  else if (ch == 'C')
    imgTmp = controller.contrast(imgFilter, val);
  else if (ch == 'S')
    imgTmp = controller.saturation(imgFilter, val, type);
  else if (ch == 'H')
    imgTmp = controller.hue(imgFilter, val, type);
  else if (ch == 'L')
    imgTmp = controller.lightness(imgFilter, val, type);
  ui->img->setPixmap(QPixmap::fromImage(imgTmp));
}

void MainWindow::colorSave(int val) {
  if (!val)
    ui->img->setPixmap(QPixmap::fromImage(imgStart));
  else
    ui->img->setPixmap(QPixmap::fromImage(imgTmp));
}

}  // namespace s21
