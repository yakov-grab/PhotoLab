#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../model/model.h"

namespace s21 {
class Controller {
 public:
  QImage grayscale(const QImage &img);
  QImage negative(const QImage &img);
  QImage toning(const QImage &img);
  QImage emboss(const QImage &img);
  QImage sharpen(const QImage &img);
  QImage boxBlur(const QImage &img);
  QImage gaussianBlur(const QImage &img);
  QImage laplacian(const QImage &img);
  QImage sobel(const QImage &img);
  QImage sobelRight(const QImage &img);
  QImage sobelLeft(const QImage &img);
  QImage kernel(const QImage &img, const QList<int> &kernel);
  QImage brightness(const QImage &img, const int val);
  QImage contrast(const QImage &img, const int val);
  QImage saturation(const QImage &img, const int val, int type);
  QImage hue(const QImage &img, const int val, int type);
  QImage lightness(const QImage &img, const int val, int type);

 private:
  Model model;
};

}  // namespace s21
#endif
