#pragma once
#include <fstream>
#include <iostream>
namespace UTester {

#define REDTEXT(str) "\33[31m" << str << "\33[0m"
#define GREENTEXT(str) "\33[32m" << str << "\33[0m"
class TestStatus {
public:
  TestStatus() noexcept;
  ~TestStatus() noexcept;

private:
  template <typename T> struct Test {
  public:
    Test() = delete;
    Test(T expectedResult, T result) : m_functionOutput(result) {
      m_testPass = _testResult(expectedResult);
    };
    ~Test() = default;

    bool m_testPass;
    T m_functionOutput;

  private:
    bool _testResult(T expectedResult) {
      return m_functionOutput == expectedResult;
    };
  };

public:
  template <typename T> void newTest(T expectedResult, T result) {
    Test<T> newTest(expectedResult, result);
    if (newTest.m_testPass)
      std::cout << GREENTEXT("PASSED") << '\n';
    else
      std::cout << REDTEXT("FAILED") << '\n';
    // writeResultsToFile(expectedResult, result);
  }
  template <typename T> void writeResultsToFile(T expectedResult, T result) {
    std::ofstream writer("Test " + std::to_string(_numberOfTests) + ".md");

    writer.close();
  }

private:
  int _numberOfTests = 0;
  int _numberOfPasses = 0;
  unsigned _totalMemoryAllocations = 0;
  unsigned _totalMemoryAllocated = 0;
  unsigned _totalMemoryLeaked = 0;
};

}; // namespace UTester
