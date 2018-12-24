#ifndef CAMERA_H
#define CAMERA_H

#include "CoordinateSystem.h"
#include "Point.h"

class Camera : public CoordinateSystem {

public:
  Point2D transformAndPerspective(Point3D point, const CoordinateSystem &other) const {
    return perspective(transformIntoSystem(point, other));
  }

  static Point2D perspective(Point3D p) {
    return Point2D(p[0] / -p[2], p[1] / -p[2]);
  }

};

#endif
