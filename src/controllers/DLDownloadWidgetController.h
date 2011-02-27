#ifndef __DL_DOWNLOAD_WIDGET_CONTROLLER_H__
#define __DL_DOWNLOAD_WIDGET_CONTROLLER_H__

#include <glib-object.h>
#include <gtk/gtk.h>
#include <gio/gio.h>

#include "../widgets/DLDownloadWidget.h"

#define DL_TYPE_DOWNLOAD_WIDGET_CONTROLLER            (dl_download_widget_controller_get_type ())
#define DL_DOWNLOAD_WIDGET_CONTROLLER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), DL_TYPE_DOWNLOAD_WIDGET_CONTROLLER, DLDownloadWidgetController))
#define DL_IS_DOWNLOAD_WIDGET_CONTROLLER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DL_TYPE_DOWNLOAD_WIDGET_CONTROLLER))
#define DL_DOWNLOAD_WIDGET_CONTROLLER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), DL_TYPE_DOWNLOAD_WIDGET_CONTROLLER, DLDownloadWidgetControllerClass))
#define DL_IS_DOWNLOAD_WIDGET_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DL_TYPE_DOWNLOAD_WIDGET_CONTROLLER))
#define DL_DOWNLOAD_WIDGET_CONTROLLER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), DL_TYPE_DOWNLOAD_WIDGET_CONTROLLER, DLDownloadWidgetControllerClass))


typedef struct _DLDownloadWidgetController        DLDownloadWidgetController;
typedef struct _DLDownloadWidgetControllerClass   DLDownloadWidgetControllerClass;
typedef struct _DLDownloadWidgetControllerPrivate DLDownloadWidgetControllerPrivate;

struct _DLDownloadWidgetController
{
    GObject *parent_instance;

    DLDownloadWidgetControllerPrivate *priv;
    DLDownloadWidget *downloadWidget;
};

struct _DLDownloadWidgetControllerClass
{
    GObjectClass *parent_class;

    void (*match_with_str)(DLDownloadWidgetController *self);
    GtkWidget *(*get_download_widget)(DLDownloadWidgetController *self);
};

// Public methonds

GType dl_download_widget_controller_get_type();

DLDownloadWidgetController *dl_download_widget_controller_new();
void dl_download_widget_controller_match_with_str(DLDownloadWidgetController *self /*params*/);
// get_download_widget_if_matched_string
GString *dl_download_widget_controller_get_file_basename(DLDownloadWidgetController *self);
GDate *dl_download_widget_controller_get_created_at_date(DLDownloadWidgetController *self);
GtkWidget *dl_download_widget_controller_get_download_widget(DLDownloadWidgetController *self);


#endif // __DL_DOWNLOAD_WIDGET_CONTROLLER_H__
