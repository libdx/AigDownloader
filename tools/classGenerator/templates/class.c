#include "PREFIXSuffix.h"
#include <gtk/gtk.h>

// Real virtual method prototypes
//void prefix_suffix_virt_method_real(PREFIXSuffix *self);

// Signals' callbacks
//void prefix_suffix_member_do(gpointer selfRef, GtkObject *gtkObject);

// Private methods
void prefix_suffix_dispose(GObject *gobject);
void prefix_suffix_finalize(GObject *gobject);

void prefix_suffix_perform_download(PREFIXSuffix *self);
void prefix_suffix_download_progress(goffset currentNumBytes, goffset totalNumBytes, gpointer selfRef);
void prefix_suffix_download_finished(GObject *sourceObject, GAsyncResult *result, gpointer selfRef);

// Private defenitions
#define PREFIX_SUFFIX_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), PREFIX_TYPE_SUFFIX, PREFIXSuffixPrivate))

struct _PREFIXSuffixPrivate
{
    //GObject *member;
};

G_DEFINE_TYPE(PREFIXSuffix, prefix_suffix, PARENT_TYPE_MACROS);

// Class constructor
static void prefix_suffix_class_init(PREFIXSuffixClass *klass)
{
    GObjectClass *gobjectClass = G_OBJECT_CLASS(klass);
    
    gobjectClass->dispose = prefix_suffix_dispose;
    gobjectClass->finalize = prefix_suffix_finalize;

    //klass->virt_method = prefix_suffix_virt_method_real;

    g_type_class_add_private(klass, sizeof(PREFIXSuffixPrivate));
}

static void prefix_suffix_init(PREFIXSuffix *self)
{
    PREFIXSuffixPrivate *priv = NULL;

    priv = PREFIX_SUFFIX_GET_PRIVATE(self);
    self->priv = priv;
    
    // init private members
}

PREFIXSuffix *prefix_suffix_new()
{
    return g_object_new(PREFIX_TYPE_SUFFIX, NULL);
}

// Virtual method's wrappers
//void prefix_suffix_virt_method(PREFIXSuffix *self)
//{
//    PREFIX_SUFFIX_GET_CLASS(self)->virt_method(self);
//}

// Real virtual methods
//void prefix_suffix_virt_method_real(PREFIXSuffix *self)
//{
//  do something
//}


// Deallocation
void prefix_suffix_dispose(GObject *gobject)
{
    //PREFIXSuffix *self = PREFIX_SUFFIX(gobject);

    //if (self->priv->member)
    //{
    //    g_object_unref(G_OBJECT(self->priv->member));
    //    self->priv->member = NULL;
    //}
    G_OBJECT_CLASS(prefix_suffix_parent_class)->dispose(gobject);
}

void prefix_suffix_finalize(GObject *gobject)
{
}
