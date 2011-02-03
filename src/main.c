#include <gtk/gtk.h>
#include <gio/gio.h>
#include "DLApplication.h"

// TODO release data before quit application

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    DLApplication *application = dl_application_new();
    dl_application_run(application);

    gtk_main();

    return 0;
}
