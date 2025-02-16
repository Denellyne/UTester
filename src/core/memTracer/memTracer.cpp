#include "memTracer.h"
#include <cstdlib>

static inline void updateMemoryAllocations(int size, bool isAllocating) {
  if (!isAllocating) {
    UTester::memTracer::_totalMemoryLeaked -= size;
    return;
  }
  UTester::memTracer::_totalMemoryAllocations++;
  UTester::memTracer::_totalMemoryAllocated += size;
  UTester::memTracer::_totalMemoryLeaked += size;
}

void *operator new(size_t size) {
  size_t *ptr = (size_t *)malloc(size + sizeof(size));
  ptr[0] = size;
  updateMemoryAllocations(size, true);
  return (void *)(&ptr[1]);
}

void operator delete(void *ptr) throw() {
  size_t *truePointer = (size_t *)ptr;
  truePointer = &truePointer[-1];
  size_t size = truePointer[0];

  updateMemoryAllocations(size, false);

  free((void *)(truePointer));
}
