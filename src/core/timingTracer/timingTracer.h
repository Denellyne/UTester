#pragma once
#include <chrono>
#include <cstdint>
#include <iostream>
#include <unordered_map>

namespace uTester {

class timingTracer {
public:
  void startTimer(uintptr_t ptr);
  void stopTimer(uintptr_t ptr);

private:
  struct functionTimer {
    ~functionTimer() {
      if (calls == 0)
        return;
      std::cout << timeSpent / calls << '\n';
    }
    void __attribute__((no_instrument_function)) start() {
      calls++;
      startTimepoint = std::chrono::high_resolution_clock::now();
    }
    void __attribute__((no_instrument_function)) stop() {
      endTimePoint = std::chrono::high_resolution_clock::now();

      auto start =
          std::chrono::time_point_cast<std::chrono::nanoseconds>(startTimepoint)
              .time_since_epoch()
              .count();
      auto end =
          std::chrono::time_point_cast<std::chrono::nanoseconds>(endTimePoint)
              .time_since_epoch()
              .count();

      timeSpent += (end - start);
    }
    unsigned calls = 0;
    unsigned timeSpent = 0;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTimepoint,
        endTimePoint;
  };

  std::unordered_map<uintptr_t, functionTimer> map;
};

} // namespace uTester
