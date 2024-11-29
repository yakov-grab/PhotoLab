#include <gtest/gtest.h>

#include <QDebug>

#include "../model/model.h"

constexpr double error = 1e-1;

TEST(PHOTOLAB_TEST, grayscale) {
  s21::Model model;

  QImage img1("../../../misc/images/sample.png");
  QImage img2("../../../misc/images/sample-bw-average.png");
  QImage result(model.grayscale(img1));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img2.pixelColor(i, j).redF(), result.pixelColor(i, j).redF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).greenF(), result.pixelColor(i, j).greenF(),0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).blueF(), result.pixelColor(i, j).blueF(), 0.1);
    }
  }
}

TEST(PHOTOLAB_TEST, negative) {
  s21::Model model;

  QImage img1("../../../misc/images/sample.png");
  QImage img2("../../../misc/images/sample-negative.png");
  QImage result(model.negative(img1));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img2.pixelColor(i, j).redF(), result.pixelColor(i, j).redF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).greenF(), result.pixelColor(i, j).greenF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).blueF(), result.pixelColor(i, j).blueF(), 0.1);
    }
  }
}

TEST(PHOTOLAB_TEST, emboss) {
  s21::Model model;

  QImage img1("../../../misc/images/sample.png");
  QImage img2("../../../misc/images/sample-ebmoss.png");
  QImage result(model.emboss(img1));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img2.pixelColor(i, j).redF(), result.pixelColor(i, j).redF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).greenF(), result.pixelColor(i, j).greenF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).blueF(), result.pixelColor(i, j).blueF(), 0.1);
    }
  }
}

TEST(PHOTOLAB_TEST, sharpen) {
  s21::Model model;

  QImage img1("../../../misc/images/sample.png");
  QImage img2("../../../misc/images/sample-sharpen.png");
  QImage result(model.sharpen(img1));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img2.pixelColor(i, j).redF(), result.pixelColor(i, j).redF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).greenF(), result.pixelColor(i, j).greenF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).blueF(), result.pixelColor(i, j).blueF(), 0.1);
    }
  }
}

TEST(PHOTOLAB_TEST, boxBlur) {
  s21::Model model;

  QImage img1("../../../misc/images/sample.png");
  QImage img2("../../../misc/images/sample-box-blur.png");
  QImage result(model.boxBlur(img1));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img2.pixelColor(i, j).redF(), result.pixelColor(i, j).redF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).greenF(), result.pixelColor(i, j).greenF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).blueF(), result.pixelColor(i, j).blueF(), 0.1);
    }
  }
}

TEST(PHOTOLAB_TEST, gaussianBlur) {
  s21::Model model;

  QImage img1("../../../misc/images/sample.png");
  QImage img2("../../../misc/images/sample-gaussian-blur.png");
  QImage result(model.gaussianBlur(img1));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img2.pixelColor(i, j).redF(), result.pixelColor(i, j).redF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).greenF(), result.pixelColor(i, j).greenF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).blueF(), result.pixelColor(i, j).blueF(), 0.1);
    }
  }
}


TEST(PHOTOLAB_TEST, laplacian) {
  s21::Model model;

  QImage img1("../../../misc/images/sample.png");
  QImage img2("../../../misc/images/sample-outline.png");
  QImage result(model.laplacian(img1));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img2.pixelColor(i, j).redF(), result.pixelColor(i, j).redF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).greenF(), result.pixelColor(i, j).greenF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).blueF(), result.pixelColor(i, j).blueF(), 0.1);
    }
  }
}

TEST(PHOTOLAB_TEST, sobelLeft) {
  s21::Model model;

  QImage img1("../../../misc/images/sample.png");
  QImage img2("../../../misc/images/sample-sobel-left.png");
  QImage result(model.sobelLeft(img1));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img2.pixelColor(i, j).redF(), result.pixelColor(i, j).redF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).greenF(), result.pixelColor(i, j).greenF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).blueF(), result.pixelColor(i, j).blueF(), 0.1);
    }
  }
}

TEST(PHOTOLAB_TEST, sobelRight) {
  s21::Model model;

  QImage img1("../../../misc/images/sample.png");
  QImage img2("../../../misc/images/sample-sobel-right.png");
  QImage result(model.sobelRight(img1));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img2.pixelColor(i, j).redF(), result.pixelColor(i, j).redF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).greenF(), result.pixelColor(i, j).greenF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).blueF(), result.pixelColor(i, j).blueF(), 0.1);
    }
  }
}

TEST(PHOTOLAB_TEST, sobel) {
  s21::Model model;

  QImage img1("../../../misc/images/sample.png");
  QImage img2("../../../misc/images/sample-sobel-right.png");
  QImage result(model.sobel(img1));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img2.pixelColor(i, j).redF(), result.pixelColor(i, j).redF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).greenF(), result.pixelColor(i, j).greenF(), 0.1);
      ASSERT_NEAR(img2.pixelColor(i, j).blueF(), result.pixelColor(i, j).blueF(), 0.1);
    }
  }
}

TEST(PHOTOLAB_TEST, brightness) {
  s21::Model model;

  QImage img1("../../../misc/images/sample.png");
  QImage result(model.brightness(img1, -100));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img1.pixelColor(i, j).lightness(), result.pixelColor(i, j).lightness(), 0.1);
    }
  }
}
