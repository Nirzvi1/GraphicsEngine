#ifndef FACE_H
#define FACE_H

#include "Point.h"
#include <vector>
#include <Eigen/Dense>

using Eigen::Vector3f;
using std::vector;

class Face : public vector<Point3D> {

  Vector3f colour;

public:
  Face(Vector3f colour=Vector3f(-1,-1,-1)) : vector<Point3D>{}, colour{colour} {}
  Face(std::initializer_list<Point3D> ls, Vector3f colour=Vector3f(-1,-1,-1)) : vector<Point3D>{ls}, colour{colour} {}

  Vector3f getColour() { return colour; }
  void setColour(Vector3f col) { colour = col; }

};

#endif
