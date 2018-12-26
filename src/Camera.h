#ifndef CAMERA_H
#define CAMERA_H

#include "CoordinateSystem.h"
#include "Point.h"

class Camera : public CoordinateSystem {


public:
  size_t canvasWidth, canvasHeight;

  Camera(size_t width=100, size_t height=100) : CoordinateSystem{}, canvasWidth{width}, canvasHeight{height} {}
  Camera(Matrix4d m, size_t width=100, size_t height=100) : CoordinateSystem{m}, canvasWidth{width}, canvasHeight{height} {}

  Point2D transformAndPerspective(Point3D point, const CoordinateSystem &other) const {
    return perspective(transformIntoSystem(point, other));
  }

  Point2D perspective(Point3D p) const {
    Point2D px(p[0] / -p[2], p[1] / -p[2]);

    if (std::abs(px[0]) > canvasWidth / 2 || std::abs(px[1]) > canvasHeight / 2 || p[2] > 0) {
      return Point2D(-1, -1);
    } else {
      return Point2D((px[0] + canvasWidth / 2) / canvasWidth, (px[1] + canvasHeight / 2) / canvasHeight);
    }
  }

};

#endif
