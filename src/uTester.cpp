#include "uTester.h"

UTester::TestStatus::TestStatus() noexcept {
  std::cout << "Test diagnostic:\n";
}
UTester::TestStatus::~TestStatus() noexcept {
  std::cout << "Tests: " << _numberOfPasses << " of " << _numberOfTests
            << " passed\n";
}
