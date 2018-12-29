#ifndef OBJECT_H
#define OBJECT_H

#include "CoordinateSystem.h"
#include "Face.h"
#include <vector>
#include <Eigen/Dense>

using Eigen::Vector3d;
using std::vector;

struct Object : CoordinateSystem {

  //we'll be allowing public access to these faces until further notice
  vector<Face> faces;

  Object() : CoordinateSystem{} {}
  Object(const Matrix4d &m) : CoordinateSystem{m} {}
  Object(Vector3d origin, Vector3d orientation) : CoordinateSystem{} {
    translate(origin);
    rotateX(orientation[0]);
    rotateY(orientation[1]);
    rotateZ(orientation[2]);
  }

};

#endif
