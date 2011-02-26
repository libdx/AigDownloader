#include "DLApplication.h"
#include <gtk/gtk.h>
#include <gio/gio.h>

// Real virtual method prototypes
void dl_application_run_real(DLApplication *self);

// Signals' callbacks
void dl_application_download_button_clicked(gpointer selfRef, GtkObject *gtkObject);

// Private methods
void dl_application_dispose(GObject *gobject);

void dl_application_perform_download(DLApplication *self);
void dl_application_download_progress(goffset currentNumBytes, goffset totalNumBytes, gpointer selfRef);
void dl_application_download_finished(GObject *sourceObject, GAsyncResult *result, gpointer selfRef);

// Private defenitions
#define DL_APPLICATION_GET_PRIVATE(obj)      (G_TYPE_INSTANCE_GET_PRIVATE ((obj), DL_TYPE_APPLICATION, DLApplicationPrivate))

struct _DLApplicationPrivate
{
    GtkWidget *mainWindow;
    GtkWidget *urlEntry;
    GtkWidget *downloadButton;
    GtkWidget *progressBar;

    GtkButton *addDownload;
    GList *downloadWidgetControllers;
};

G_DEFINE_TYPE(DLApplication, dl_application, G_TYPE_OBJECT);

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
    GtkBuilder *builder = gtk_builder_new();
    GError *error = NULL;
    gtk_builder_add_from_file(builder, "resources/DLMainWindow.glade", &error);
    gtk_builder_connect_signals(builder, NULL);

    self->priv->mainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "mainWindow"));
    self->priv->urlEntry = GTK_WIDGET(gtk_builder_get_object(builder, "urlEntry"));
    self->priv->downloadButton = GTK_WIDGET(gtk_builder_get_object(builder, "downloadButton"));
    self->priv->progressBar = GTK_WIDGET(gtk_builder_get_object(builder, "downloadProgressBar"));

    g_signal_connect_swapped(self->priv->downloadButton, "clicked",
        G_CALLBACK(dl_application_download_button_clicked), self);
    
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(self->priv->progressBar), 0.0f);

    g_object_unref(G_OBJECT(builder));
}

DLApplication *dl_application_new()
{
    return g_object_new(DL_TYPE_APPLICATION, NULL);
}

// Virtual method's wrappers
void dl_application_run(DLApplication *self)
{
    DL_APPLICATION_GET_CLASS(self)->run(self);
}

// Real virtual methods of this class

void dl_application_run_real(DLApplication *self)
{
    gtk_widget_show(self->priv->mainWindow); 
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

// Signals' callbacks
void dl_application_download_button_clicked(gpointer selfRef, GtkObject *gtkObject)
{
    DLApplication *self = DL_APPLICATION(selfRef);
    dl_application_perform_download((self));
}

void dl_application_perform_download(DLApplication *self)
{
    GFile *inFile = g_file_new_for_uri(gtk_entry_get_text(GTK_ENTRY(self->priv->urlEntry)));
    char *inFileBasename = g_file_get_basename(inFile);
    GFile *outFile = g_file_new_for_path(inFileBasename);

    g_file_copy_async(inFile, outFile,
        G_FILE_COPY_BACKUP, G_PRIORITY_DEFAULT, NULL,
        dl_application_download_progress, self,
        dl_application_download_finished, self);
}
void dl_application_download_progress(goffset currentNumBytes, goffset totalNumBytes, gpointer selfRef)
{
    DLApplication *self = DL_APPLICATION(selfRef);

    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(self->priv->progressBar), (gdouble)currentNumBytes / (gdouble)totalNumBytes);
    g_print("\rProgress: %f%%",(gdouble)((gdouble)currentNumBytes) / (gdouble)totalNumBytes * 100);
}

void dl_application_download_finished(GObject *sourceObject, GAsyncResult *result, gpointer selfRef)
{
    g_print("\nDownloading is finished\n");
}
