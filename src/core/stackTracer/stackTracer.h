#pragma once
#include "../timingTracer/timingTracer.h"

// static uTester::timingTracer test;
extern "C" {
void __cyg_profile_func_enter(void *this_fn, void *call_site)
    __attribute__((no_instrument_function));
void __cyg_profile_func_exit(void *this_fn, void *call_site)
    __attribute__((no_instrument_function));
}
