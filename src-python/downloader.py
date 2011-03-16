#!/usr/bin/env python

import pygtk
import gobject, gio, gtk, os


class DLApplication(gobject.GObject):
    def __init__(self):
        builder = gtk.Builder()
        builder.add_from_file('resources/DLMainWindow.glade')
        self._mainWindow = builder.get_object('mainWindow')
        self._urlEntry = builder.get_object('urlEntry')
        self._downloadButton = builder.get_object('downloadButton')
        self._progressBar = builder.get_object('progressBar')

        self._mainWindow.connect("destroy", self.on_destroy)

    def run(self):
        self._mainWindow.show()

    def on_destroy(self, data = None):
        gtk.main_quit()


if __name__ == "__main__":
    app = DLApplication()
    app.run()
    gtk.main()
