#ifndef __DL_APPLICATION_H__
#define __DL_APPLICATION_H__

#include <glib-object.h>
#include <gtk/gtk.h>
#include <gio/gio.h>

#define DL_TYPE_APPLICATION                  (dl_application_get_type ())
#define DL_APPLICATION(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), DL_TYPE_APPLICATION, DLApplication))
#define DL_IS_APPLICATION(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DL_TYPE_APPLICATION))
#define DL_APPLICATION_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), DL_TYPE_APPLICATION, DLApplicationClass))
#define DL_IS_APPLICATION_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), DL_TYPE_APPLICATION))
#define DL_APPLICATION_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), DL_TYPE_APPLICATION, DLApplicationClass))

typedef struct _DLApplication DLApplication;
typedef struct _DLApplicationPrivate DLApplicationPrivate;
typedef struct _DLApplicationClass DLApplicationClass;

struct _DLApplication
{
    GObject parent_instance;

    DLApplicationPrivate *priv;
};

struct _DLApplicationClass
{
    GObjectClass parent_class;

    // Virtual Methods
    void (*run)(DLApplication *);
};

GType dl_application_get_type();

DLApplication *dl_application_new();
void dl_application_run(DLApplication *self);

void dl_application_dispose(GObject *gobject);


#endif // __DL_APPLICATION_H__
