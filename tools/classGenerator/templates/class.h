#ifndef __PREFIX_SUFFIX_H__
#define __PREFIX_SUFFIX_H__

#include <glib-object.h>
#include <gtk/gtk.h>

#define PREFIX_TYPE_SUFFIX                  (prefix_suffix_get_type ())
#define PREFIX_SUFFIX(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), PREFIX_TYPE_SUFFIX, PREFIXSuffix))
#define PREFIX_IS_SUFFIX(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PREFIX_TYPE_SUFFIX))
#define PREFIX_SUFFIX_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), PREFIX_TYPE_SUFFIX, PREFIXSuffixClass))
#define PREFIX_IS_SUFFIX_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), PREFIX_TYPE_SUFFIX))
#define PREFIX_SUFFIX_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), PREFIX_TYPE_SUFFIX, PREFIXSuffixClass))

typedef struct _PREFIXSuffix PREFIXSuffix;
typedef struct _PREFIXSuffixPrivate PREFIXSuffixPrivate;
typedef struct _PREFIXSuffixClass PREFIXSuffixClass;

struct _PREFIXSuffix
{
    ParentType parent_instance;

    PREFIXSuffixPrivate *priv;
};

struct _PREFIXSuffixClass
{
    ParentTypeClass parent_class;

    // Virtual Methods
    //void (*virt_method)(PREFIXSuffix *);
};

GType prefix_suffix_get_type();

PREFIXSuffix *prefix_suffix_new();
void prefix_suffix_run(PREFIXSuffix *self);

#endif // __PREFIX_SUFFIX_H__
