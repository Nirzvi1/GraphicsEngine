#ifndef WORLD_H
#define WORLD_H

#include "Camera.h"
#include "Object.h"
#include <cairo.h>
#include <gtk/gtk.h>
#include <iostream>
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
      Point2D start = c.transformAndPerspective(o.getPoints()[0], identity);


      cairo_move_to(cr, start[0] + w / 2, start[1] + h / 2);

      for (auto p : o.getPoints()) {
        Point2D px = c.transformAndPerspective(p, identity);
        std::cout << px[0] << "; " << px[1] << std::endl;

        cairo_line_to(cr, px[0] + w / 2, px[1] + h / 2);
      }

      cairo_close_path(cr);
    }

    cairo_stroke(cr);
  }

  vector<Object> &getObjects() { return objects; }
  vector<Camera> &getCameras() { return cameras; }

};

#endif
