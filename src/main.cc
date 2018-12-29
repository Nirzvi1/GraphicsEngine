#include "World.h"
#include "Object.h"
#include "Camera.h"
#include "Point3D.h"
#include "polyhedrons/Cube.h"
#include "polyhedrons/Tetrahedron.h"
#include <cairo.h>
#include <gtk/gtk.h>

static gboolean clicked(GtkWidget *widget, GdkEventKey *event, gpointer user_data) {

    if (event->keyval == GDK_KEY_a){
        World *w = static_cast<World *>(user_data);
        w->getCameras()[0].translate(Vector3d(-2, 0, 0));

        gtk_widget_queue_draw(widget);

        return TRUE;
    } else if (event->keyval == GDK_KEY_d){
        World *w = static_cast<World *>(user_data);
        w->getCameras()[0].translate(Vector3d(2, 0, 0));

        gtk_widget_queue_draw(widget);

        return TRUE;
    } else if (event->keyval == GDK_KEY_w){
        World *w = static_cast<World *>(user_data);
        w->getCameras()[0].translate(Vector3d(0, -2, 0));

        gtk_widget_queue_draw(widget);

        return TRUE;
    } else if (event->keyval == GDK_KEY_s){
        World *w = static_cast<World *>(user_data);
        w->getCameras()[0].translate(Vector3d(0, 2, 0));

        gtk_widget_queue_draw(widget);

        return TRUE;
    } else if (event->keyval == GDK_KEY_f){
        World *w = static_cast<World *>(user_data);
        w->getCameras()[0].translate(Vector3d(0, 0, -0.5));

        gtk_widget_queue_draw(widget);

        return TRUE;
    } else if (event->keyval == GDK_KEY_b){
        World *w = static_cast<World *>(user_data);
        w->getCameras()[0].translate(Vector3d(0, 0, 0.5));

        gtk_widget_queue_draw(widget);

        return TRUE;
    } else if (event->keyval == GDK_KEY_e){
        World *w = static_cast<World *>(user_data);
        w->getCameras()[0].rotateX(0.01);

        gtk_widget_queue_draw(widget);

        return TRUE;
    } else if (event->keyval == GDK_KEY_q){
        World *w = static_cast<World *>(user_data);
        w->getCameras()[0].rotateX(-0.01);

        gtk_widget_queue_draw(widget);

        return TRUE;
    }

    return FALSE;
}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
  World *w = static_cast<World *>(user_data);
  w->draw(widget, cr);

  return FALSE;
}

void addDrawingArea(GtkWidget* window, World &world) {
  GtkWidget *darea = gtk_drawing_area_new();

  gtk_container_add(GTK_CONTAINER(window), darea);
  g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(on_draw_event), &world);
}

int main(int argc, char *argv[])
{
  GtkWidget *window;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);

  Object o;
  o.faces = {Face{Point3D(10, 10, 5),Point3D(-10, 10, 5),Point3D(-10, -10, 5),Point3D(10, -10, 5)},
                    Face{Point3D(20, 20, -5),Point3D(0, 20, -5),Point3D(0, 0, -5),Point3D(20, 0, -5)}};
  // Cube o(10);
  // o.getFaces()[0].setColour(Eigen::Vector3f(0.5, 0, 0));
  // o.getFaces()[1].setColour(Eigen::Vector3f(0, 0.5, 0));
  // o.getFaces()[2].setColour(Eigen::Vector3f(0, 0, 0.5));
  // o.getFaces()[3].setColour(Eigen::Vector3f(0, 0.5, 0.5));
  // o.getFaces()[4].setColour(Eigen::Vector3f(0.5, 0, 0.5));
  // o.getFaces()[5].setColour(Eigen::Vector3f(0.5, 0.5, 0));
  o.translate(Vector3d(0,0,-30));

  World w;
  w.getObjects().push_back(o);
  w.getCameras().push_back(Camera(1.54, 1));

  addDrawingArea(window, w);

  g_signal_connect(window, "destroy",
      G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect(window, "key_press_event",
      G_CALLBACK(clicked), &w);

  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 1000, 650);
  gtk_window_set_title(GTK_WINDOW(window), "Lines");

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
