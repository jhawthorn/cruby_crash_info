#include "cruby_crash_info.h"

VALUE rb_mCrubyCrashInfo;

void
Init_cruby_crash_info(void)
{
  rb_mCrubyCrashInfo = rb_define_module("CrubyCrashInfo");
}
