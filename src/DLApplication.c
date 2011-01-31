#include "DLApplication.h"
#include <gtk/gtk.h>
#include <gio/gio.h>

// Real virtual method prototypes

void dl_application_run_real(DLApplication *self);

// Private
#define DL_APPLICATION_GET_PRIVATE(obj)      (G_TYPE_INSTANCE_GET_PRIVATE ((obj), DL_TYPE_APPLICATION, DLApplicationPrivate))

struct _DLApplicationPrivate
{
    GtkWidget *urlEntry;
    GtkWidget *progressBar;
};

// Class constructor

static void dl_application_class_init(DLApplicationClass *klass)
{
    GObjectClass *gobjectClass = G_OBJECT_CLASS(klass);
    
    gobjectClass->dispose = dl_application_dispose;

    klass->run = dl_application_run_real;

    g_type_class_add_private(klass, sizeof(DLApplicationPrivate));
}

static void dl_application_init(DLApplication *self)
{
    DLApplicationPrivate *priv = NULL;

    priv = DL_APPLICATION_GET_PRIVATE(self);
    self->priv = priv;
    
    // init private members
}

DLApplication *dl_application_new()
{
    return g_object_new(DL_TYPE_APPLICATION, NULL);
}

G_DEFINE_TYPE(DLApplication, dl_application, G_TYPE_OBJECT);

// Virtual method's wrappers
void dl_application_run(DLApplication *self)
{
    DL_APPLICATION_GET_CLASS(self)->run(self);
}

// Real virtual methods of this class

void dl_application_run_real(DLApplication *self)
{
    GtkBuilder *builder = gtk_builder_new();
    GError *error = NULL;
    gtk_builder_add_from_file(builder, "resources/DLMainWindow.glade", &error);
    gtk_builder_connect_signals(builder, NULL);

    GtkWidget *mainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "mainWindow"));
    self->priv->urlEntry = GTK_WIDGET(gtk_builder_get_object(builder, "urlEntry"));
    self->priv->progressBar = GTK_WIDGET(gtk_builder_get_object(builder, "downloadProgressBar"));
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(self->priv->progressBar), 0.0f);

    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(mainWindow); 
}


// Deallocation
void dl_application_dispose(GObject *gobject)
{
    DLApplication *self = DL_APPLICATION(gobject);

    if (self->priv->urlEntry)
    {
        g_object_unref(G_OBJECT(self->priv->urlEntry));
        self->priv->urlEntry = NULL;
    }
    if (self->priv->progressBar)
    {
        g_object_unref(G_OBJECT(self->priv->progressBar));
        self->priv->progressBar = NULL;
    }
    G_OBJECT_CLASS(dl_application_parent_class)->dispose(gobject);
}
