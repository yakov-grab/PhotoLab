#ifndef MODEL_H
#define MODEL_H

#include <QColor>
#include <QColorDialog>
#include <QImage>
#include <QLabel>
#include <cmath>
#include <vector>

namespace s21 {
class Model {
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
  QImage kernel(const QImage &img, QList<int> kernel);
  QImage brightness(const QImage &img, int val);
  QImage contrast(const QImage &img, int val);
  QImage saturation(const QImage &img, int val, int type);
  QImage hue(const QImage &img, int val, int type);
  QImage lightness(const QImage &img, int val, int type);
};
}  // namespace s21
#endif
