#ifndef _EASY_TIMER_HPP
#define _EASY_TIMER_HPP

#include <chrono>
#include <iostream>

template <class Unit = std::chrono::seconds,
          class Clock = std::chrono::high_resolution_clock>
class easyTimer {
private:
  std::chrono::time_point<Clock> start{};
  std::string prefix;

public:
  easyTimer() : start(Clock::now()), prefix("Time Elapsed: ") {}
  easyTimer(std::string prefix) : start(Clock::now()), prefix(prefix) {}
  ~easyTimer() {
    const std::chrono::duration<double> elapsed(Clock::now() - start);
    std::cout << prefix << std::chrono::duration_cast<Unit>(elapsed).count()
              << deduceUnit() << std::endl;
  }
  const char *deduceUnit() {
#if __cplusplus >= 201703L
    if constexpr
#else
    if
#endif
        (std::is_same<Unit, std::chrono::nanoseconds>::value) {
      return "ns";
    } else if (std::is_same<Unit, std::chrono::microseconds>::value) {
      return "us";
    } else if (std::is_same<Unit, std::chrono::milliseconds>::value) {
      return "ms";
    } else if (std::is_same<Unit, std::chrono::seconds>::value) {
      return "s";
    } else if (std::is_same<Unit, std::chrono::hours>::value) {
      return "h";
    }
#if __cplusplus >= 202002L
    else if (std::is_same<Unit, std::chrono::days>::value) {
      return "d";
    } else if (std::is_same<Unit, std::chrono::weeks>::value) {
      return "w";
    } else if (std::is_same<Unit, std::chrono::months>::value) {
      return "m";
    } else if (std::is_same<Unit, std::chrono::years>::value) {
      return "y";
    }
#else
    else {
      return "";
    }
#endif
  }
};

#endif