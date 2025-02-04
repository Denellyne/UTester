#include "uTester.h"

UTester::TestStatus::TestStatus(bool writeToFile) noexcept
    : writeToFile(writeToFile) {
  std::cout << "Test diagnostic:\n";
}
UTester::TestStatus::~TestStatus() noexcept {
  std::cout << "Tests: " << _numberOfPasses << " of " << _numberOfTests
            << " passed\n";

  std::cout << "Total memory allocations: " << _totalMemoryAllocations << '\n'
            << "Total memory allocated: " << _totalMemoryAllocated << '\n'
            << "Total memory leaked: " << _totalMemoryLeaked << '\n';
}

void *operator new(size_t size) {
  size_t *ptr = (size_t *)malloc(size + sizeof(size));
  ptr[0] = size;
  UTester::TestStatus::updateMemoryAllocations(size, true);
  return (void *)(&ptr[1]);
}

void operator delete(void *ptr) throw() {
  size_t *truePointer = (size_t *)ptr;
  truePointer = &truePointer[-1];
  size_t size = truePointer[0];

  UTester::TestStatus::updateMemoryAllocations(size, false);

  free((void *)(truePointer));
}
