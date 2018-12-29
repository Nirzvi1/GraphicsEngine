#ifndef POINT_H
#define POINT_H
#include <Eigen/Dense>

using Eigen::Vector4d;
using Eigen::Vector3i;
using Point2D = Eigen::Vector2d;

class Point3D : public Vector4d {

  Vector3i colour;

public:

  Point3D(double x, double y, double z) : Vector4d{x,y,z,1}, colour{127, 127, 127} {}
  Point3D(double x, double y, double z, int r, int g, int b) : Vector4d{x,y,z,1}, colour{r,g,b} {}
  Point3D(Vector4d v) : Vector4d{v}, colour{127, 127, 127} {}

  operator Eigen::Vector3d() { return Eigen::Vector3d(this->operator[](0), this->operator[](1), this->operator[](2)); }

};

struct Pixel : public Eigen::Vector2d {
  double dist;

  Pixel(double x, double y, double dist=0) : Eigen::Vector2d{x,y}, dist{dist} {}
};

#endif
