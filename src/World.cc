#include "World.h"
#include "Object.h"
#include "Camera.h"
#include "Face.h"
#include "Shape.h"

void World::draw(GtkWidget *widget, cairo_t *cr) {
  const Camera &c = cameras[0];
  CoordinateSystem identity;

  int w = gtk_widget_get_allocated_width(widget);
  int h = gtk_widget_get_allocated_height(widget);

  vector<Shape> toDraw;

  for (auto o : objects) {
    for (auto f : o.faces) {
      Shape s;
      for (auto p : f) {
        s.push_back(c.transformAndPerspective(p, o));
      }
      toDraw.push_back(s);
    }
  }

  while(true) {
    bool found = false;
    for (auto it1 = toDraw.begin(); it1 != toDraw.end(); ++it1) {
      for (auto it2 = std::next(it1); it2 != toDraw.end(); ++it2) {
        vector<Shape> overlap = it1->clip(*it2);
        if (overlap.size() > 2) {
          toDraw.erase(it1);
          toDraw.erase(std::prev(it2)); //we know it2 is after it1 so we can fix it manually (kind of hacky)
          toDraw.insert(toDraw.begin(), overlap.begin(), overlap.end());
          found = true;
          break;
        }
      }
      if (found) {
        break;
      }
    }

    if (!found) {
      break;
    }
  }

  for (size_t k = 0; k < toDraw.size(); ++k) {

    cairo_set_source_rgb(cr, ((k / 9) % 3) * 0.3, ((k / 3) % 3) * 0.3, (k % 3) * 0.3);

    cairo_move_to(cr, w * toDraw[k][0][0], h * (1 - toDraw[k][0][1]));
    for (auto p : toDraw[k]) {
      cairo_line_to(cr, p[0] * w, (1 - p[1]) * h);
    }

    cairo_close_path(cr);
    cairo_fill(cr);
  }
}
