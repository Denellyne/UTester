#pragma once

#include <cstddef>

void *operator new(size_t size);

void operator delete(void *ptr) throw();

namespace UTester {
struct memTracer {

  static inline unsigned _totalMemoryAllocations = 0;
  static inline unsigned _totalMemoryAllocated = 0;
  static inline unsigned _totalMemoryLeaked = 0;
};

} // namespace UTester
