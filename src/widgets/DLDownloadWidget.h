#ifndef __DL_DOWNLOAD_WIDGET_H__
#define __DL_DOWNLOAD_WIDGET_H__

#include <glib-object.h>
#include <gtk/gtk.h>

#define DL_TYPE_DOWNLOAD_WIDGET                  (dl_download_widget_get_type ())
#define DL_DOWNLOAD_WIDGET(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), DL_TYPE_DOWNLOAD_WIDGET, DLDownloadWidget))
#define DL_IS_DOWNLOAD_WIDGET(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DL_TYPE_DOWNLOAD_WIDGET))
#define DL_DOWNLOAD_WIDGET_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), DL_TYPE_DOWNLOAD_WIDGET, DLDownloadWidgetClass))
#define DL_IS_DOWNLOAD_WIDGET_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), DL_TYPE_DOWNLOAD_WIDGET))
#define DL_DOWNLOAD_WIDGET_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), DL_TYPE_DOWNLOAD_WIDGET, DLDownloadWidgetClass))

typedef struct _DLDownloadWidget DLDownloadWidget;
typedef struct _DLDownloadWidgetPrivate DLDownloadWidgetPrivate;
typedef struct _DLDownloadWidgetClass DLDownloadWidgetClass;

struct _DLDownloadWidget
{
    GtkWidget parent_instance;

    DLDownloadWidgetPrivate *priv;
};

struct _DLDownloadWidgetClass
{
    GtkWidgetClass parent_class;

    // Virtual Methods
    //void (*virt_method)(DLDownloadWidget *);
};

GType dl_download_widget_get_type();

DLDownloadWidget *dl_download_widget_new();
void dl_download_widget_run(DLDownloadWidget *self);

#endif // __DL_DOWNLOAD_WIDGET_H__
