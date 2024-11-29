#include "model.h"

namespace s21 {

QImage Model::grayscale(const QImage &img) {
  if (!img.isNull()) {
    QImage tmp = img;
    tmp = tmp.convertToFormat(QImage::Format_Grayscale8);
    return tmp;
  }
  return img;
}

QImage Model::negative(const QImage &img) {
  if (!img.isNull()) {
    QImage tmp = img;
    tmp.invertPixels();
    return tmp;
  }
  return img;
}

QImage Model::toning(const QImage &img) {
  if (!img.isNull()) {
    QImage tmp = img;
    int r, g, b;
    int rS, gS, bS;

    QColor selectedColor = QColorDialog::getColor();
    selectedColor.getRgb(&rS, &gS, &bS);
    for (int i = 0; i < tmp.width(); i++) {
      for (int j = 0; j < tmp.height(); j++) {
        QColor imgColor = tmp.pixelColor(i, j);
        imgColor.getRgb(&r, &g, &b);
        imgColor.setRgb(qBound(0, r + rS / 3, 255), qBound(0, g + gS / 3, 255),
                        qBound(0, b + bS / 3, 255));
        tmp.setPixelColor(i, j, imgColor);
      }
    }
    return tmp;
  }
  return img;
}

QRgb getNewColor(const QList<int> &kernel, const QImage &img, int x, int y) {
  int kernelsize = sqrt(kernel.size());
  qreal total = 0;
  qreal red = 0;
  qreal green = 0;
  qreal blue = 0;
  for (int r = -kernelsize / 2; r <= kernelsize / 2; ++r) {
    for (int c = -kernelsize / 2; c <= kernelsize / 2; ++c) {
      int kerVal =
          kernel.at((kernelsize / 2 + r) * kernelsize + (kernelsize / 2 + c));
      total += kerVal;
      if (x + c < 1 || y + r < 1 || x + c > img.width() - 1 ||
          y + r > img.height() - 1) {
        red += qRed(img.pixel(x, y)) * kerVal;
        green += qGreen(img.pixel(x, y)) * kerVal;
        blue += qBlue(img.pixel(x, y)) * kerVal;
      } else {
        red += qRed(img.pixel(x + c, y + r)) * kerVal;
        green += qGreen(img.pixel(x + c, y + r)) * kerVal;
        blue += qBlue(img.pixel(x + c, y + r)) * kerVal;
      }
    }
  }
  if (total == 0)
    return qRgb(qBound(0, qRound(red), 255), qBound(0, qRound(green), 255),
                qBound(0, qRound(blue), 255));
  return qRgb(qBound(0, qRound(red / total), 255),
              qBound(0, qRound(green / total), 255),
              qBound(0, qRound(blue / total), 255));
}

QImage applyConvolution(const QImage &img, QImage &tmp,
                        const QList<int> &kernel) {
  for (int y = 0; y < img.height(); y++) {
    for (int x = 0; x < img.width(); x++) {
      tmp.setPixel(x, y, getNewColor(kernel, img, x, y));
    }
  }
  return tmp;
}

QImage Model::emboss(const QImage &img) {
  if (!img.isNull()) {
    QImage tmp = img;
    QList<int> emboss;
    emboss << 0 << 0 << 0 << 0 << 0 << 0 << -2 << -1 << 0 << 0 << 0 << -1 << 1
           << 1 << 0 << 0 << 0 << 1 << 2 << 0 << 0 << 0 << 0 << 0 << 0;
    return applyConvolution(img, tmp, emboss);
  }
  return img;
}

QImage Model::sharpen(const QImage &img) {
  if (!img.isNull()) {
    QImage tmp = img;
    QList<int> sharpen;
    sharpen << 0 << 0 << 0 << 0 << 0 << 0 << 0 << -1 << 0 << 0 << 0 << -1 << 5
            << -1 << 0 << 0 << 0 << -1 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
    return applyConvolution(img, tmp, sharpen);
  }
  return img;
}

QImage Model::boxBlur(const QImage &img) {
  if (!img.isNull()) {
    QImage tmp = img;
    QList<int> blur;
    blur << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 3 << 1 << 0 << 1 << 3 << 7 << 3
         << 1 << 0 << 1 << 3 << 1 << 0 << 0 << 0 << 1 << 0 << 0;
    return applyConvolution(img, tmp, blur);
  }
  return img;
}

QImage Model::gaussianBlur(const QImage &img) {
  if (!img.isNull()) {
    QImage tmp = img;
    QList<int> gaussian;
    gaussian << 0 << 0 << 0 << 0 << 0 << 0 << 1 << 1 << 1 << 0 << 0 << 1 << 2
             << 1 << 0 << 0 << 1 << 1 << 1 << 0 << 0 << 0 << 0 << 0 << 0;
    return applyConvolution(img, tmp, gaussian);
  }
  return img;
}

QImage Model::laplacian(const QImage &img) {
  if (!img.isNull()) {
    QImage tmp = img;
    QList<int> laplacian;
    laplacian << 0 << 0 << 0 << 0 << 0 << 0 << -1 << -1 << -1 << 0 << 0 << -1
              << 8 << -1 << 0 << 0 << -1 << -1 << -1 << 0 << 0 << 0 << 0 << 0
              << 0;
    return applyConvolution(grayscale(img), tmp, laplacian);
  }
  return img;
}

QImage Model::sobelRight(const QImage &img) {
  if (!img.isNull()) {
    QImage tmp = img;
    QList<int> sobelRight;
    sobelRight << 0 << 0 << 0 << 0 << 0 << 0 << -1 << 0 << 1 << 0 << 0 << -2
               << 0 << 2 << 0 << 0 << -1 << 0 << 1 << 0 << 0 << 0 << 0 << 0
               << 0;
    return applyConvolution(grayscale(img), tmp, sobelRight);
  }
  return img;
}

QImage Model::sobelLeft(const QImage &img) {
  if (!img.isNull()) {
    QImage tmp = img;
    QList<int> sobelLeft;
    sobelLeft << 0 << 0 << 0 << 0 << 0 << 0 << 1 << 0 << -1 << 0 << 0 << 2 << 0
              << -2 << 0 << 0 << 1 << 0 << -1 << 0 << 0 << 0 << 0 << 0 << 0;
    return applyConvolution(grayscale(img), tmp, sobelLeft);
  }
  return img;
}

int getPixelRgb(const QImage &img, int x, int y, int xOffset, int yOffset) {
  int color = (QColor(img.pixel(x + xOffset, y + yOffset)).red() +
               QColor(img.pixel(x + xOffset, y + yOffset)).green() +
               QColor(img.pixel(x + xOffset, y + yOffset)).blue()) /
              3;
  return color;
}

QImage Model::sobel(const QImage &img) {
  if (!img.isNull()) {
    QImage tmp = img;
    int kernelx[3][3] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int kernely[3][3] = {1, 2, 1, 0, 0, 0, -1, -2, -1};

    for (int y = 1; y < img.height() - 1; y++) {
      for (int x = 1; x < img.width() - 1; x++) {
        int a = getPixelRgb(img, x, y, -1, -1);
        int b = getPixelRgb(img, x, y, 0, -1);
        int c = getPixelRgb(img, x, y, 1, -1);
        int d = getPixelRgb(img, x, y, -1, 0);
        int e = getPixelRgb(img, x, y, 0, 0);
        int f = getPixelRgb(img, x, y, 1, 0);
        int g = getPixelRgb(img, x, y, -1, 1);
        int h = getPixelRgb(img, x, y, 0, 1);
        int i = getPixelRgb(img, x, y, 1, 1);
        int matrix[3][3] = {a, b, c, d, e, f, g, h, i};
        int sumx = 0;
        int sumy = 0;

        for (int s = 0; s < 3; s++) {
          for (int t = 0; t < 3; t++) {
            sumx = sumx + (matrix[s][t] * kernelx[s][t]);
            sumy = sumy + (matrix[s][t] * kernely[s][t]);
          }
        }

        int newValue = sqrt(pow(sumx, 2) + pow(sumy, 2));
        if (newValue < 0) {
          newValue = 0;
        }
        if (newValue > 255) {
          newValue = 255;
        }

        QColor newColor = QColor(img.pixel(x, y));
        newColor.setRed(newValue);
        newColor.setBlue(newValue);
        newColor.setGreen(newValue);
        tmp.setPixel(x, y, newColor.rgb());
      }
    }
    return tmp;
  }
  return img;
}

QImage Model::kernel(const QImage &img, QList<int> kernel) {
  if (!img.isNull()) {
    QImage tmp = img;
    return applyConvolution(img, tmp, kernel);
  }
  return img;
}

QImage Model::brightness(const QImage &img, const int val) {
  if (!img.isNull()) {
    QImage tmp = img;
    int r, g, b;
    for (int i = 0; i < tmp.width(); i++) {
      for (int j = 0; j < tmp.height(); j++) {
        QColor imgColor = img.pixelColor(i, j);
        imgColor.getRgb(&r, &g, &b);
        imgColor.setRgb(qBound(0, r + val, 255), qBound(0, g + val, 255),
                        qBound(0, b + val, 255));
        tmp.setPixelColor(i, j, imgColor);
      }
    }
    return tmp;
  }
  return img;
}

QImage Model::contrast(const QImage &img, const int val) {
  if (!img.isNull()) {
    QImage tmp = img;
    int r, g, b;
    float contrast = qBound(
        -255.f, (259 * ((float)val + 255)) / (255 * (259 - (float)val)), 255.f);
    for (int i = 0; i < tmp.width(); i++) {
      for (int j = 0; j < tmp.height(); j++) {
        QColor imgColor = img.pixelColor(i, j);
        imgColor.getRgb(&r, &g, &b);
        imgColor.setRgb(qBound(0.f, contrast * (r - 128) + 128, 255.f),
                        qBound(0.f, contrast * (g - 128) + 128, 255.f),
                        qBound(0.f, contrast * (b - 128) + 128, 255.f));
        tmp.setPixelColor(i, j, imgColor);
      }
    }
    return tmp;
  }
  return img;
}

QImage Model::saturation(const QImage &img, const int val, int type) {
  if (!img.isNull()) {
    QImage tmp = img;
    for (int i = 0; i < tmp.width(); i++) {
      for (int j = 0; j < tmp.height(); j++) {
        QColor imgColor;
        if (type) {
          imgColor = img.pixelColor(i, j).convertTo(QColor::Hsv);
          imgColor.setHsv(imgColor.hue(),
                          qBound(0, imgColor.saturation() + val - 128, 255),
                          imgColor.lightness());
        } else {
          imgColor = img.pixelColor(i, j).convertTo(QColor::Hsl);
          imgColor.setHsl(imgColor.hue(),
                          qBound(0, imgColor.saturation() + val - 128, 255),
                          imgColor.lightness());
        }
        tmp.setPixelColor(i, j, imgColor);
      }
    }
    return tmp;
  }
  return img;
}

QImage Model::hue(const QImage &img, const int val, int type) {
  if (!img.isNull()) {
    QImage tmp = img;
    for (int i = 0; i < tmp.width(); i++) {
      for (int j = 0; j < tmp.height(); j++) {
        QColor imgColor;
        if (type) {
          imgColor = img.pixelColor(i, j).convertTo(QColor::Hsv);
          imgColor.setHsv(qBound(0, imgColor.hue() + val - 128, 255),
                          imgColor.saturation(), imgColor.lightness());
        } else {
          imgColor = img.pixelColor(i, j).convertTo(QColor::Hsl);
          imgColor.setHsl(qBound(0, imgColor.hue() + val - 128, 255),
                          imgColor.saturation(), imgColor.lightness());
        }
        tmp.setPixelColor(i, j, imgColor);
      }
    }
    return tmp;
  }
  return img;
}

QImage Model::lightness(const QImage &img, const int val, int type) {
  if (!img.isNull()) {
    QImage tmp = img;
    for (int i = 0; i < tmp.width(); i++) {
      for (int j = 0; j < tmp.height(); j++) {
        QColor imgColor;
        if (type) {
          imgColor = img.pixelColor(i, j).convertTo(QColor::Hsv);
          imgColor.setHsv(imgColor.hue(), imgColor.saturation(),
                          qBound(0, imgColor.lightness() + val - 128, 255));
        } else {
          imgColor = img.pixelColor(i, j).convertTo(QColor::Hsl);
          imgColor.setHsl(imgColor.hue(), imgColor.saturation(),
                          qBound(0, imgColor.lightness() + val - 128, 255));
        }
        tmp.setPixelColor(i, j, imgColor);
      }
    }
    return tmp;
  }
  return img;
}

}  // namespace s21
