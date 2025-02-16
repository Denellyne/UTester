#include "uTester.h"

UTester::TestStatus::TestStatus(bool writeToFile) noexcept
    : writeToFile(writeToFile) {
  std::cout << "Test diagnostic:\n";
}
UTester::TestStatus::~TestStatus() noexcept {
  std::cout << "Tests: " << _numberOfPasses << " of " << _numberOfTests
            << " passed\n";

  std::cout << "Total memory allocations: "
            << UTester::memTracer::_totalMemoryAllocations << '\n'
            << "Total memory allocated: "
            << UTester::memTracer::_totalMemoryAllocated << '\n'
            << "Total memory leaked: " << UTester::memTracer::_totalMemoryLeaked
            << '\n';
}
