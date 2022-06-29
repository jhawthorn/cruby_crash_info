#include "cruby_crash_info.h"

static VALUE rb_mCrubyCrashInfo;

int rb_bug_reporter_add(void (*func)(FILE *, void *), void *data);

static VALUE extra_debug_info = Qnil;

static VALUE rb_set_extra_debug_info(VALUE self, VALUE str) {
    Check_Type(str, T_STRING);
    extra_debug_info = str;
    return str;
}

static VALUE rb_get_extra_debug_info(VALUE self) {
    return extra_debug_info;
}

static void report_extra_crash_info(FILE *f, void *data) {
    if (!RTEST(extra_debug_info)) return;

    fprintf(f, " * Extra crash info:\n");
    fwrite(RSTRING_PTR(extra_debug_info), 1, RSTRING_LEN(extra_debug_info), f);
    fprintf(f, "\n\n");
}

void
Init_cruby_crash_info(void)
{
  rb_mCrubyCrashInfo = rb_define_module("CRubyCrashInfo");
  rb_define_singleton_method(rb_mCrubyCrashInfo, "info=", rb_set_extra_debug_info, 1);
  rb_define_singleton_method(rb_mCrubyCrashInfo, "info", rb_get_extra_debug_info, 0);
  rb_gc_register_address(&extra_debug_info);
  rb_bug_reporter_add(report_extra_crash_info, NULL);
}
