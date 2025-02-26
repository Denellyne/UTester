#pragma once
#include "../timingTracer/timingTracer.h"
#include <cstdint>

inline static uTester::timingTracer test;
extern "C" {

void __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *this_fn, void *call_site);

void __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *this_fn, void *call_site);
}
