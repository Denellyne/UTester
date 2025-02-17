#pragma once
#include <chrono>
#include <cstdint>
#include <iostream>
#include <unordered_map>

namespace uTester {

class timingTracer {
public:
  timingTracer() { std::cout << "constructed\n"; }
  void a(uintptr_t ptr) { map[ptr].start(); }
  void b(uintptr_t ptr) { map[ptr].stop(); }

private:
  struct functionTimer {
    ~functionTimer() {
      if (calls == 0)
        return;
      std::cout << timeSpent / calls << '\n';
    }
    void start() {
      calls++;
      startTimepoint = std::chrono::high_resolution_clock::now();
    }
    void stop() {
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
