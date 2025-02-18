#include "timingTracer.h"
#include <cstdint>

void __attribute__((no_instrument_function))
uTester::timingTracer::startTimer(uintptr_t ptr) {
  map[ptr].start();
}
void __attribute__((no_instrument_function))
uTester::timingTracer::stopTimer(uintptr_t ptr) {
  map[ptr].stop();
}
