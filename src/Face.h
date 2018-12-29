#ifndef FACE_H
#define FACE_H

#include <vector>
#include <Eigen/Dense>

using Eigen::Vector3f;
using std::vector;

class Point3D;

class Face : public vector<Point3D> {
public:
  Face() : vector<Point3D>{} {}
  Face(std::initializer_list<Point3D> ls) : vector<Point3D>{ls} {}

};

#endif
