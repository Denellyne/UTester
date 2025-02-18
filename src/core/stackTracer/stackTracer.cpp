#include "stackTracer.h"
void __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *this_fn, void *call_site) {

  test.stopTimer((uintptr_t)(this_fn));
}

void __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *this_fn, void *call_site) {
  test.startTimer((uintptr_t)(this_fn));
}
