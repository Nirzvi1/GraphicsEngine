#include "World.h"

void World::draw(GtkWidget *widget, cairo_t *cr) {
  const Camera &c = cameras[0];
  CoordinateSystem identity;

  int w = gtk_widget_get_allocated_width(widget);
  int h = gtk_widget_get_allocated_height(widget);

  vector<Shape> toDraw;

  for (auto o : objects) {
    for (auto f : o.getFaces()) {
      Shape s;
      for (auto p : f) {
        s.push_back(c.transformAndPerspective(p, o));
      }
      toDraw.push_back(s);
    }
  }

  for (auto i = toDraw.begin(); i != toDraw.end(); ++i) {
    for (auto j = std::next(i); j != toDraw.end(); ++j) {
      vector<Shape> overlapped = i->intersect(*j);
      if (overlapped.size() > 2) {
          toDraw.erase(i);
          toDraw.erase(j);
          toDraw.insert(toDraw.end(), overlapped.begin(), overlapped.end());
          break;
      }
    }
  }


  for (size_t k = 0; k < toDraw.size(); ++k) {

    std::cout << ((k / 9) % 3) * 85 << "; " << ((k / 3) % 3) * 85 << "; " << (k % 3) * 85 << std::endl;
    cairo_set_source_rgb(cr, ((k / 9) % 3) * 0.3, ((k / 3) % 3) * 0.3, (k % 3) * 0.3);

    cairo_move_to(cr, w * toDraw[k][0][0], h * (1 - toDraw[k][0][1]));
    for (auto p : toDraw[k]) {
      std::cout << p << std::endl;
      cairo_line_to(cr, p[0] * w, (1 - p[1]) * h);
    }

    cairo_close_path(cr);
    cairo_fill(cr);
  }
}
