#ifndef OBJECT_H
#define OBJECT_H

#include "CoordinateSystem.h"
#include "Point.h"
#include "Face.h"
#include <vector>
#include <Eigen/Dense>

using Eigen::Vector3d;
using std::vector;

class Object : public CoordinateSystem {
  vector<Face> faces;

public:
  Object() : CoordinateSystem{} {}
  Object(const Matrix4d &m) : CoordinateSystem{m} {}
  Object(Vector3d origin, Vector3d orientation) : CoordinateSystem{} {
    translate(origin);
    rotateX(orientation[0]);
    rotateY(orientation[1]);
    rotateZ(orientation[2]);
  }

  void setFaces(const vector<Face> &f) { faces = f; }
  vector<Face> &getFaces() { return faces; }

};

#endif
