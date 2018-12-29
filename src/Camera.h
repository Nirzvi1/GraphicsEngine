#ifndef CAMERA_H
#define CAMERA_H

#include "CoordinateSystem.h"
#include "Point3D.h"
#include "Pixel.h"

class Camera : public CoordinateSystem {

public:
  double canvasWidth, canvasHeight;

  Camera(double width=1, double height=1) : CoordinateSystem{}, canvasWidth{width}, canvasHeight{height} {}
  Camera(Matrix4d m, double width=1, double height=1) : CoordinateSystem{m}, canvasWidth{width}, canvasHeight{height} {}

  Pixel transformAndPerspective(Point3D point, const CoordinateSystem &other) const {
    return perspective(transformIntoSystem(point, other));
  }

  Pixel perspective(Point3D p) const {
    Pixel px(p[0] / -p[2], p[1] / -p[2], std::sqrt(p[0]*p[0] + p[1]*p[1] + p[2]*p[2]));

    return Pixel((px[0] + canvasWidth / 2) / canvasWidth, (px[1] + canvasHeight / 2) / canvasHeight, std::sqrt(p[0]*p[0] + p[1]*p[1] + p[2]*p[2]));
  }

  static bool outOfView(Pixel p) {
    return (p[0] < 0 || p[0] > 1 || p[1] < 0 || p[1] > 1);
  }

  bool outOfView(Point3D p) const {
    return (std::abs(p[0]) > canvasWidth / 2 || std::abs(p[1]) > canvasHeight / 2 || p[2] > 0);
  }

};

#endif
