#ifndef OBJECT_H
#define OBJECT_H

#include "CoordinateSystem.h"
#include "Point.h"
#include <vector>

using std::vector;

class Object : public CoordinateSystem {
  vector<Point3D> points;

public:

  vector<Point3D> &getPoints() { return points; }

};

#endif
