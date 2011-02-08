#include "DLDownloadWidgetController.h"
#include <gtk/gtk.h>
#include <gio/gio.h>

// Private real methods prototypes
void dl_download_widget_controller_match_with_str_real(DLDownloadWidgetController *self);

// Private prototypes
void dl_download_widget_controller_dispose(GObject *object);

// Private defenitions
#define DL_DOWNLOAD_WIDGET_CONTROLLER_GET_PRIVATE(obj) \
    (G_TYPE_INSTANCE_GET_PRIVATE ((obj), DL_TYPE_DOWNLOAD_WIDGET_CONTROLLER, DLDownloadWidgetControllerPrivate))

struct _DLDownloadWidgetControllerPrivate
{
    GtkWidget *downloadWidget; // in future in will be DLDownloadWidget
    GTree *dataTree; // May be use a HashTable?
};

G_DEFINE_TYPE(DLDownloadWidgetController, dl_download_widget_controller, G_TYPE_OBJECT);

void dl_download_widget_controller_class_init(DLDownloadWidgetControllerClass *klass)
{
    GObjectClass *gobjectClass = G_OBJECT_CLASS(klass);
    
    gobjectClass->dispose = dl_download_widget_controller_dispose;
    
    klass->match_with_str = dl_download_widget_controller_match_with_str_real;
    
    g_type_class_add_private(klass, sizeof(DLDownloadWidgetControllerPrivate));
}

void dl_download_widget_controller_init(DLDownloadWidgetController *self)
{
    self->priv = DL_DOWNLOAD_WIDGET_CONTROLLER_GET_PRIVATE(self);

    // init private members
}

DLDownloadWidgetController *dl_download_widget_controller_new()
{
    return g_object_new(DL_TYPE_DOWNLOAD_WIDGET_CONTROLLER, NULL);
}

void dl_download_widget_controller_match_with_str(DLDownloadWidgetController *self /*params*/)
{
    return DL_DOWNLOAD_WIDGET_CONTROLLER_GET_CLASS(self)->match_with_str(self);
}

// Deallocation
void dl_application_dispose(GObject *gobject)
{
    DLDownloadWidgetController *self = DL_DOWNLOAD_WIDGET_CONTROLLER(gobject);

    if (NULL != self->priv->downloadWidget)
    {
        g_object_unref(G_OBJECT(self->priv->downloadWidget));
        self->priv->downloadWidget = NULL;
    }
    if (NULL != self->priv->dataTree)
    {
        g_object_unref(G_OBJECT(self->priv->dataTree));
        self->priv->dataTree = NULL;
    }
    G_OBJECT_CLASS(dl_download_widget_controller_parent_class)->dispose(gobject);
}

// Real methods implementation
void dl_download_widget_controller_match_with_str_real(DLDownloadWidgetController *self)
{
    //GPtrArray *ptrArray = NULL;
    //return ptrArray;
}
