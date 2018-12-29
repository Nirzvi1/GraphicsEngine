#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <vector>

using std::vector;

using point_xy = boost::geometry::model::d2::point_xy<double>;
using polygon_2d = boost::geometry::model::polygon<point_xy>;

class Shape : public vector<Pixel> {

public:
  static Shape toShape(const polygon_2d &boostS) {
    using boost::geometry::get;

    Shape s;
    boost::geometry::for_each_point(boostS, [&s](point_xy p) { s.push_back(Pixel(boost::geometry::get<0>(p),boost::geometry::get<1>(p))); });

    return s;
  }

  static polygon_2d toBoostPolygon(const Shape &s) {
    polygon_2d boostS;

    vector<point_xy> v;
    v.resize(s.size());
    std::transform(s.begin(), s.end(), v.begin(), [](Pixel p){ return point_xy(p[0], p[1]); });
    boost::geometry::assign_points(boostS, v);

    return boostS;
  }

  vector<Shape> intersect(Shape &other) {

    polygon_2d boostThis = toBoostPolygon(*this);
    polygon_2d boostOther = toBoostPolygon(other);

    boost::geometry::correct(boostThis);
    boost::geometry::correct(boostOther);

    vector<Shape> v;

    vector<polygon_2d> inDiff;
    boost::geometry::sym_difference(boostThis, boostOther, inDiff);
    v.resize(v.size() + inDiff.size());
    std::transform(inDiff.begin(), inDiff.end(), v.begin(), [] (polygon_2d &p) { return toShape(p); });

    vector<polygon_2d> inBoth;
    vector<Shape> inBothShapes;
    boost::geometry::intersection(boostThis, boostOther, inBoth);
    inBothShapes.resize(inBoth.size());
    std::transform(inBoth.begin(), inBoth.end(), inBothShapes.begin(), [] (polygon_2d &p) { return toShape(p); });
    v.insert(v.end(), inBothShapes.begin(), inBothShapes.end());

    return v;
  }

};

#endif
