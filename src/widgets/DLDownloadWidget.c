#include "DLDownloadWidget.h"
#include <gtk/gtk.h>

// Real virtual method prototypes
//void dl_download_widget_virt_method_real(DLDownloadWidget *self);

// Signals' callbacks
//void dl_download_widget_member_do(gpointer selfRef, GtkObject *gtkObject);

// Private methods
void dl_download_widget_dispose(GObject *gobject);
void dl_download_widget_finalize(GObject *gobject);

void dl_download_widget_perform_download(DLDownloadWidget *self);
void dl_download_widget_download_progress(goffset currentNumBytes, goffset totalNumBytes, gpointer selfRef);
void dl_download_widget_download_finished(GObject *sourceObject, GAsyncResult *result, gpointer selfRef);

// Private defenitions
#define DL_DOWNLOAD_WIDGET_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), DL_TYPE_DOWNLOAD_WIDGET, DLDownloadWidgetPrivate))

struct _DLDownloadWidgetPrivate
{
    //GObject *member;
};

G_DEFINE_TYPE(DLDownloadWidget, dl_download_widget, GTK_TYPE_WIDGET);

// Class constructor
static void dl_download_widget_class_init(DLDownloadWidgetClass *klass)
{
    GObjectClass *gobjectClass = G_OBJECT_CLASS(klass);
    
    gobjectClass->dispose = dl_download_widget_dispose;
    gobjectClass->finalize = dl_download_widget_finalize;

    //klass->virt_method = dl_download_widget_virt_method_real;

    g_type_class_add_private(klass, sizeof(DLDownloadWidgetPrivate));
}

static void dl_download_widget_init(DLDownloadWidget *self)
{
    DLDownloadWidgetPrivate *priv = NULL;

    priv = DL_DOWNLOAD_WIDGET_GET_PRIVATE(self);
    self->priv = priv;
    
    // init private members
}

DLDownloadWidget *dl_download_widget_new()
{
    return g_object_new(DL_TYPE_DOWNLOAD_WIDGET, NULL);
}

// Virtual method's wrappers
//void dl_download_widget_virt_method(DLDownloadWidget *self)
//{
//    DL_DOWNLOAD_WIDGET_GET_CLASS(self)->virt_method(self);
//}

// Real virtual methods
//void dl_download_widget_virt_method_real(DLDownloadWidget *self)
//{
//  do something
//}


// Deallocation
void dl_download_widget_dispose(GObject *gobject)
{
    //DLDownloadWidget *self = DL_DOWNLOAD_WIDGET(gobject);

    //if (self->priv->member)
    //{
    //    g_object_unref(G_OBJECT(self->priv->member));
    //    self->priv->member = NULL;
    //}
    G_OBJECT_CLASS(dl_download_widget_parent_class)->dispose(gobject);
}

void dl_download_widget_finalize(GObject *gobject)
{
}
