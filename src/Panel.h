#ifndef PANEL_H
#define PANEL_H

#include "World.h"
#include <cairo.h>
#include <gtk/gtk.h>

class Panel {

  GtkWidget *area;

  static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    World *w = static_cast<World *>(user_data);
    w->draw(widget, cr);

    return FALSE;
  }

public:
  Panel(GtkWidget *win, World &world) : area{gtk_drawing_area_new()} {
    gtk_container_add(GTK_CONTAINER(win), area);
    g_signal_connect(G_OBJECT(area), "draw", G_CALLBACK(on_draw_event), &world);
  }

};

#endif
