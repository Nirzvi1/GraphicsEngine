#include "World.h"
#include "Object.h"
#include "Point.h"
#include "Panel.h"
#include <cairo.h>
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *darea;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);

  World w;

  Object o;
  o.getPoints().push_back(Point3D(100, 100, 10, 1));
  o.getPoints().push_back(Point3D(-100, 100, 10, 1));
  o.getPoints().push_back(Point3D(-100, -100, 10, 1));
  o.getPoints().push_back(Point3D(100, -100, 10, 1));

  Object o2;
  o2.getPoints().push_back(Point3D(100, 100, 20, 1));
  o2.getPoints().push_back(Point3D(-100, 100, 20, 1));
  o2.getPoints().push_back(Point3D(-100, -100, 20, 1));
  o2.getPoints().push_back(Point3D(100, -100, 20, 1));

    Object o3;
    o3.getPoints().push_back(Point3D(100, 100, 10, 1));
    o3.getPoints().push_back(Point3D(100, -100, 10, 1));
    o3.getPoints().push_back(Point3D(100, -100, 20, 1));
    o3.getPoints().push_back(Point3D(100, 100, 20, 1));

  w.getObjects().push_back(o);
  w.getObjects().push_back(o2);
  w.getObjects().push_back(o3);

  w.getCameras().push_back(Camera());
  w.getCameras()[0].translate(Vector3d(0, 0, 0));

  Panel p(window, w);

  g_signal_connect(window, "destroy",
      G_CALLBACK(gtk_main_quit), NULL);

  // g_signal_connect(window, "button-press-event",
  //     G_CALLBACK(clicked), &p);

  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
  gtk_window_set_title(GTK_WINDOW(window), "Lines");

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
