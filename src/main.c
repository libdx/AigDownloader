#include <gtk/gtk.h>
#include <gio/gio.h>

// TODO release data before quit application

// Some global var used as class's members as if the main function were application controller
GtkWidget *gUrlEntry = NULL;

// Signals
G_MODULE_EXPORT void download_button_clicked(GtkObject *gtkObject, gpointer userData);

// Downloading
void perform_download();
// Different download mechanisms
void perform_download_by_reading();
void perform_download_by_copying();

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkBuilder *builder = gtk_builder_new();
    GError *error = NULL;
    gtk_builder_add_from_file(builder, "resources/DLMainWindow.glade", &error);
    gtk_builder_connect_signals(builder, NULL);

    GtkWidget *mainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "mainWindow"));
    gUrlEntry = GTK_WIDGET(gtk_builder_get_object(builder, "urlEntry"));

    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(mainWindow); 

    gtk_main();

    return 0;
}

// Signals
G_MODULE_EXPORT void download_button_clicked(GtkObject *gtkObject, gpointer userData)
{
    perform_download();
}

// Downloading
void perform_download()
{
    perform_download_by_reading();
}

// Different download mechanisms
void perform_download_by_reading()
{
    GError *error = NULL;

    GFile *inFile = g_file_new_for_uri(gtk_entry_get_text(GTK_ENTRY(gUrlEntry)));
    GFileInputStream *fileInputStream = g_file_read(inFile, NULL, &error);

    g_print("start downloading file: %s\n", gtk_entry_get_text(GTK_ENTRY(gUrlEntry)));
    char *inFileBasename = g_file_get_basename(inFile);
    g_print("file basename: %s\n", inFileBasename);
    g_object_unref(G_OBJECT(inFile));

    GFile *outFile = g_file_new_for_path(inFileBasename);
    GFileOutputStream *fileOutputStream = g_file_create(outFile, G_FILE_CREATE_NONE, NULL, &error);
    gssize fileSize = g_output_stream_splice(
        G_OUTPUT_STREAM(fileOutputStream),
        G_INPUT_STREAM(fileInputStream),
        G_OUTPUT_STREAM_SPLICE_CLOSE_SOURCE, NULL, &error);
    g_print("File size: %d\n", (int)fileSize);

    g_object_unref(G_OBJECT(outFile));
    g_object_unref(G_OBJECT(fileInputStream));
    g_object_unref(G_OBJECT(fileOutputStream));
}

void perform_download_by_copying()
{
}
