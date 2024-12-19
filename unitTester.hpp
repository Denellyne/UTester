#pragma once
#include <iostream>
#include <ostream>
#include <string>

struct TestStatus {
  int numberOfTests = 0;
  int numberOfPasses = 0;

  TestStatus() noexcept { std::cout << "Test diagnostic:\n"; }
  ~TestStatus() noexcept {
    std::cout << "Tests: " << numberOfPasses << " of " << numberOfTests
              << " passed\n";
  }
};
static TestStatus status;
template <class T> struct UTest {
  bool passed;
  T expected;
  T result;
  std::string description;
  std::string output;

  UTest() = delete;

  template <typename function, class... Args>
  UTest(T output, std::string descp, function func)
      : expected(output), result(func), description(descp) {
    status.numberOfTests++;
    passed = expected == result;
    description = "\33[34m" + description + "\33[0m";
    std::cout << *this;
  }
  const friend std::ostream &operator<<(std::ostream &os,
                                        UTest &test) noexcept {
    if (test.passed) {
      status.numberOfPasses++;
      test.output = "\33[32m[PASSED]\033[0m";
      return os << test.output << ' ' << test.description << '\n';
    }

    test.output = "\33[31m[FAILED]\033[0m";
    return os << test.output << ' ' << test.description << '\n'
              << "Expected: " << test.expected << " Result: " << test.result
              << '\n';
  }
};
