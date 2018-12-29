#ifndef WORLD_H
#define WORLD_H

#include <cairo.h>
#include <gtk/gtk.h>
#include <vector>

using std::vector;

struct Object;
class Camera;

class World {

  vector<Object> objects;
  vector<Camera> cameras;

public:

  void draw(GtkWidget *widget, cairo_t *cr);

  vector<Object> &getObjects() { return objects; }
  vector<Camera> &getCameras() { return cameras; }

};

#endif
