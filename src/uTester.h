#pragma once
#include <fstream>
#include <iostream>

void *operator new(size_t size);

void operator delete(void *ptr) throw();

namespace UTester {

#define REDTEXT(str) "\33[31m" << str << "\33[0m"
#define GREENTEXT(str) "\33[32m" << str << "\33[0m"
class TestStatus {
public:
  TestStatus() noexcept;
  ~TestStatus() noexcept;

private:
  template <typename T> struct Test {
    Test() = delete;
    Test(T expectedResult, T result)
        : m_testPass(expectedResult == result), expectedResult(expectedResult),
          result(result) {};

    ~Test() {
      std::cout << "Test " << TestStatus::_numberOfTests << ':';
      if (m_testPass)
        std::cout << GREENTEXT(" PASSED") << '\n';
      else {

        std::cout << REDTEXT(" FAILED") << '\n';
        std::cout << "  Expected result: " << expectedResult << '\n';
        std::cout << "  Result: " << result << '\n';
      }

      // writeResultsToFile(expectedResult, result);
    }

    bool m_testPass;

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
    Test<T> newTest(expectedResult, result);
    _numberOfTests++;

    if (newTest.m_testPass)
      _numberOfPasses++;
  }

  static inline void updateMemoryAllocations(int size, bool isAllocating) {
    if (!isAllocating) {
      _totalMemoryLeaked -= size;
      return;
    }
    _totalMemoryAllocations++;
    _totalMemoryAllocated += size;
    _totalMemoryLeaked += size;
  }

private:
  static inline unsigned _numberOfTests = 0;
  static inline unsigned _numberOfPasses = 0;
  static inline unsigned _totalMemoryAllocations = 0;
  static inline unsigned _totalMemoryAllocated = 0;
  static inline unsigned _totalMemoryLeaked = 0;
};

}; // namespace UTester
