#include "controller.h"

namespace s21 {

QImage Controller::grayscale(const QImage &img) { return model.grayscale(img); }
QImage Controller::negative(const QImage &img) { return model.negative(img); }
QImage Controller::toning(const QImage &img) { return model.toning(img); }
QImage Controller::emboss(const QImage &img) { return model.emboss(img); }
QImage Controller::sharpen(const QImage &img) { return model.sharpen(img); }
QImage Controller::boxBlur(const QImage &img) { return model.boxBlur(img); }
QImage Controller::gaussianBlur(const QImage &img) {
  return model.gaussianBlur(img);
}
QImage Controller::laplacian(const QImage &img) { return model.laplacian(img); }
QImage Controller::sobel(const QImage &img) { return model.sobel(img); }
QImage Controller::sobelRight(const QImage &img) {
  return model.sobelRight(img);
}
QImage Controller::sobelLeft(const QImage &img) { return model.sobelLeft(img); }
QImage Controller::kernel(const QImage &img, const QList<int> &kernel) {
  return model.kernel(img, kernel);
}
QImage Controller::brightness(const QImage &img, const int val) {
  return model.brightness(img, val);
}
QImage Controller::contrast(const QImage &img, const int val) {
  return model.contrast(img, val);
}
QImage Controller::saturation(const QImage &img, const int val, int type) {
  return model.saturation(img, val, type);
}
QImage Controller::hue(const QImage &img, const int val, int type) {
  return model.hue(img, val, type);
}
QImage Controller::lightness(const QImage &img, const int val, int type) {
  return model.lightness(img, val, type);
}

}  // namespace s21
