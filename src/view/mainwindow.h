#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>

#include "../controller/controller.h"
#include "interface.h"
#include "kernel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  void ShowStartImage();
  void ShowFilteredImage();

  QImage imgStart;
  QImage imgFilter;
  QImage imgTmp;

  Controller controller;
  Kernel kernel;
  Interface interface;

  bool startImg = true;

 private slots:
  void on_loadImg_clicked();
  void on_saveImg_clicked();
  void on_clearImg_clicked();
  void on_grayscale_clicked();
  void on_negative_clicked();
  void on_toning_clicked();
  void on_emboss_clicked();
  void on_sharpen_clicked();
  void on_boxBlur_clicked();
  void on_gaussianBlur_clicked();
  void on_laplacian_clicked();
  void on_sobel_clicked();
  void on_sobelRight_clicked();
  void on_sobelLeft_clicked();
  void on_kernel_clicked();
  void brightness();
  void contrast();
  void saturation();
  void on_colorInter_clicked();
  void imgChange(char ch, int val);
  void colorSave(int val);
  void hue(int val);

  void kernelList(QList<int> kernel);
};

}  // namespace s21
#endif  // MAINWINDOW_H
