#ifndef WORLD_H
#define WORLD_H

#include "Camera.h"
#include "Object.h"
#include <cairo.h>
#include <gtk/gtk.h>
#include <vector>

class World {

  vector<Object> objects;
  vector<Camera> cameras;

public:

  void draw(GtkWidget *widget, cairo_t *cr) {
    const Camera &c = cameras[0];
    CoordinateSystem identity;

    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_set_line_width(cr, 0.5);

    int w = gtk_widget_get_allocated_width(widget);
    int h = gtk_widget_get_allocated_height(widget);

    for (auto o : objects) {
      for (auto f : o.getFaces()) {
        Point2D start = c.transformAndPerspective(f[0], o);
        size_t sc = c.canvasWidth;

        cairo_move_to(cr, start[0] * sc * w - (sc-1) * w / 2, (1 - start[1]) * sc * h - (sc-1) * h / 2);
        for (size_t i = 1; i < f.size(); ++i) {
          Point2D px = c.transformAndPerspective(f[i], o);
          if (px[0] != -1 && px[1] != -1)
            cairo_line_to(cr, px[0] * sc * w - (sc-1) * w / 2, (1 - px[1]) * sc * h - (sc-1) * h / 2);
        }

        cairo_close_path(cr);
      }
    }

    cairo_stroke(cr);
  }

  vector<Object> &getObjects() { return objects; }
  vector<Camera> &getCameras() { return cameras; }

};

#endif
