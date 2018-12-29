#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <Eigen/Dense>

using Eigen::Vector3d;
using std::vector;

class Cube : public Object {

  double length;

public:

  static vector<Face> makeCubeFaces(double l) {
    vector<Face> v;

    Point3D LUF = Point3D(l/2,l/2,l/2); //Left, Up, Forward
    Point3D LUB = Point3D(l/2,l/2,-l/2); //Left, Up, Back
    Point3D LDF = Point3D(l/2,-l/2,l/2); //Left, Down, Forward
    Point3D LDB = Point3D(l/2,-l/2,-l/2); //Left, Down, Back
    Point3D RUF = Point3D(-l/2,l/2,l/2); //Left, Up, Forward
    Point3D RUB = Point3D(-l/2,l/2,-l/2); //Left, Up, Back
    Point3D RDF = Point3D(-l/2,-l/2,l/2); //Left, Down, Forward
    Point3D RDB = Point3D(-l/2,-l/2,-l/2); //Left, Down, Back

    v.push_back(Face{LUF, LDF, RDF, RUF});
    v.push_back(Face{LUB, LDB, RDB, RUB});
    v.push_back(Face{LUF, LUB, LDB, LDF});
    v.push_back(Face{RUF, RUB, RDB, RDF});
    v.push_back(Face{LUF, RUF, RUB, LUB});
    v.push_back(Face{LDF, RDF, RDB, LDB});

    return v;
  }

  Cube(double l=1) : Object{}, length{l} {
    faces = makeCubeFaces(l);
  }

  Cube(const Matrix4d &m, double l=1) : Object{m}, length{l} {
    faces = makeCubeFaces(l);
  }

  Cube(Vector3d origin, Vector3d orientation, double l=1) : Object{origin, orientation}, length{l} {
    faces = makeCubeFaces(l);
  }


};

#endif
