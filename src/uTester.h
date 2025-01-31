#pragma once

#include <iostream>
namespace UTester {

#define REDTEXT(x) "\33[34m" + x + "\33[0m"
#define GREENTEXT(x) "\33[32m" + x + "\33[0m"
template <class T> class TestStatus {
public:
  TestStatus() noexcept { std::cout << "Test diagnostic:\n"; }
  ~TestStatus() noexcept {
    std::cout << "Tests: " << _numberOfPasses << " of " << _numberOfTests
              << " passed\n";
  }

private:
  template <class function, class... args> struct Test {
  public:
    Test() = delete;
    Test(T expectedResult, function fn, args... arguments)
        : m_functionOutput(fn(arguments...)) {
      m_testPass = _testResult(expectedResult);
    };
    ~Test();

    bool m_testPass;
    T m_functionOutput;

  private:
    bool _testResult(T expectedResult) {
      return m_functionOutput == expectedResult;
    };
  };

private:
  int _numberOfTests = 0;
  int _numberOfPasses = 0;
  unsigned _totalMemoryAllocations = 0;
  unsigned _totalMemoryAllocated = 0;
  unsigned _totalMemoryLeaked = 0;
};

}; // namespace UTester
