#include "Shape.h"

vector<point_xy> Shape::toBoostVector() {
  vector<point_xy> v;
  for (auto p : *this) {
    v.push_back(p);
  }

  return v;
}

vector<Shape> Shape::clip(Shape &other) {

  polygon_2d boostThis = *this;
  polygon_2d boostOther = other;

  boost::geometry::correct(boostThis);
  boost::geometry::correct(boostOther);

  vector<Shape> ret;

  vector<polygon_2d> inDiff;
  boost::geometry::sym_difference(boostThis, boostOther, inDiff);

  vector<polygon_2d> inBoth;
  boost::geometry::intersection(boostThis, boostOther, inBoth);

  ret.insert(ret.end(), inDiff.begin(), inDiff.end());
  ret.insert(ret.end(), inBoth.begin(), inBoth.end());

  return ret;
}
