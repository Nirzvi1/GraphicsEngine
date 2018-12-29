#ifndef PIXEL_H
#define PIXEL_H

#include <Eigen/Dense>
#include <boost/geometry/geometries/point_xy.hpp>

using point_xy = boost::geometry::model::d2::point_xy<double>;

struct Pixel : public point_xy {
  double dist;

  Pixel(double x, double y, double dist=0) : point_xy{x,y}, dist{dist} {}
  Pixel(point_xy p) : point_xy{p}, dist{0} {}

  operator Eigen::Vector2d() {
    using boost::geometry::get;
    return Eigen::Vector2d(get<0>(static_cast<point_xy>(*this)), get<1>(static_cast<point_xy>(*this)));
  }

  //note that i == 0 or 1
  double operator[](size_t i) {
    if (i == 0) {
      return boost::geometry::get<0>(static_cast<point_xy>(*this));
    } else {
      return boost::geometry::get<1>(static_cast<point_xy>(*this));
    }
  }
};

#endif
