#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include <Eigen/Dense>

using Eigen::Vector3d;

class Tetrahedron : public Object {
  double length;

public:

  static vector<Face> makeTetraFaces(double l) {
    vector<Face> v;

    Point3D up(0,l/std::sqrt(3),0);
    Point3D forward(0, -l/std::sqrt(3), l/std::sqrt(3));
    Point3D left(l/std::sqrt(3), -l/std::sqrt(3), -l/std::sqrt(3));
    Point3D right(-l/std::sqrt(3), -l/std::sqrt(3), -l/std::sqrt(3));

    v.push_back(Face{up, left, right});
    v.push_back(Face{up, forward, left});
    v.push_back(Face{up, forward, right});
    v.push_back(Face{forward, left, right});

    return v;
  }

  Tetrahedron(double l=1) : Object{}, length{l} { faces = makeTetraFaces(l); }
  Tetrahedron(const Matrix4d &m, double l=1) : Object{m}, length{l} { faces = makeTetraFaces(l); }
  Tetrahedron(Vector3d origin, Vector3d orientation, double l=1) : Object{origin, orientation}, length{l} { faces = makeTetraFaces(l); }

};

#endif
