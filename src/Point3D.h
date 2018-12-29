#ifndef POINT3D_H
#define POINT3D_H

#include <Eigen/Dense>

using Eigen::Vector4d;

class Point3D : public Vector4d {

public:

  Point3D(double x, double y, double z) : Vector4d{x,y,z,1} {}
  Point3D(Vector4d v) : Vector4d{v} {}

  operator Eigen::Vector3d() { return Eigen::Vector3d(this->operator[](0), this->operator[](1), this->operator[](2)); }

};

#endif
