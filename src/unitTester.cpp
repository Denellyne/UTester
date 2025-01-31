#include "unitTester.hpp"

void *operator new(size_t size) {
  UTester::status.totalMemoryAllocations++;
  UTester::status.totalMemoryLeaked += size;
  UTester::status.totalMemoryAllocated += size;

  void *ptr = malloc(size);
  return ptr;
}

void operator delete(void *ptr, size_t sz) throw() {
  UTester::status.totalMemoryLeaked -= sz;
  std::cout << sz << '\n';
  free(ptr);
}
