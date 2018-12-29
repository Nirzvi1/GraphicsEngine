#ifndef WORLD_H
#define WORLD_H

#include "Camera.h"
#include "Object.h"
#include "Face.h"
#include "Shape.h"
#include <cairo.h>
#include <gtk/gtk.h>
#include <vector>
#include <iostream>

using std::vector;


class World {

  vector<Object> objects;
  vector<Camera> cameras;

public:

  void draw(GtkWidget *widget, cairo_t *cr);

  vector<Object> &getObjects() { return objects; }
  vector<Camera> &getCameras() { return cameras; }

};

#endif
