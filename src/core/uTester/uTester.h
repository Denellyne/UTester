#pragma once
#include "../memTracer/memTracer.h"
#include <fstream>
#include <iostream>

namespace UTester {

#define REDTEXT(str) "\33[31m" << str << "\33[0m"
#define GREENTEXT(str) "\33[32m" << str << "\33[0m"

class TestStatus {
public:
  TestStatus() = delete;
  TestStatus(bool writeToFile) noexcept;
  ~TestStatus() noexcept;

private:
  template <typename T> struct Test {
    Test() = delete;
    Test(T expectedResult, T result, bool writeToFile)
        : m_testPass(expectedResult == result), expectedResult(expectedResult),
          result(result), writeToFile(writeToFile) {};

    ~Test() {
      std::cout << "Test " << TestStatus::_numberOfTests << ':';

      if (m_testPass)
        std::cout << GREENTEXT(" PASSED") << '\n';

      else {
        std::cout << REDTEXT(" FAILED") << '\n';
        std::cout << "  Expected result: " << expectedResult << '\n';
        std::cout << "  Result: " << result << '\n';
      }

      if (writeToFile)
        writeResultsToFile(expectedResult, result);
    }

    bool m_testPass;
    bool writeToFile;

  private:
    void writeResultsToFile(T expectedResult, T result) {
      std::ofstream writer("Test " +
                           std::to_string(TestStatus::_numberOfTests) + ".md");

      writer << "# Test " << TestStatus::_numberOfTests << "\n\n";
      writer.close();
    }
    T expectedResult;
    T result;
  };

public:
  template <typename T> void newTest(T expectedResult, T result) {
    Test<T> newTest(expectedResult, result, writeToFile);
    _numberOfTests++;

    if (newTest.m_testPass)
      _numberOfPasses++;
  }

private:
  bool writeToFile = false;

  static inline unsigned _numberOfTests = 0;
  static inline unsigned _numberOfPasses = 0;
};

}; // namespace UTester
