#ifndef SHAPE_H
#define SHAPE_H

#include "Pixel.h"
#include "Point3D.h"
#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <vector>

using std::vector;

using point_xy = boost::geometry::model::d2::point_xy<double>;
using polygon_2d = boost::geometry::model::polygon<point_xy>;

class Shape : public vector<Pixel> {
public:

  Shape(){}

  Shape(const polygon_2d &boostS) {
    boost::geometry::for_each_point(boostS, [this](point_xy p) { this->push_back(p); });
  }

  vector<point_xy> toBoostVector();

  operator polygon_2d() {
    polygon_2d boostS;
    boost::geometry::assign_points(boostS, this->toBoostVector());
    return boostS;
  }


  vector<Shape> clip(Shape &other);

};

#endif
