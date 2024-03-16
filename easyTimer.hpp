#ifndef _EASY_TIMER_HPP
#define _EASY_TIMER_HPP

#include <chrono>
#include <iostream>

template <typename Unit = std::chrono::seconds,
          typename Clock = std::chrono::high_resolution_clock>
class easyTimer {
private:
  std::chrono::time_point<Clock> start{};
  std::string prefix, suffix;

  const char *deduceUnit() {
#if __cplusplus >= 201703L // c++17
    if constexpr
#else // c++11 (doesn't have "if constexpr")
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
#if __cplusplus >= 202002L // c++20
    else if (std::is_same<Unit, std::chrono::days>::value) {
      return "d";
    } else if (std::is_same<Unit, std::chrono::weeks>::value) {
      return "w";
    } else if (std::is_same<Unit, std::chrono::months>::value) {
      return "m";
    } else if (std::is_same<Unit, std::chrono::years>::value) {
      return "y";
    }
#else // The other units didn't exist until c++20
    else {
      return "";
    }
#endif
  }

public:
  easyTimer() : start(Clock::now()), prefix("Time Elapsed: ") {}
  easyTimer(std::string prefix) : start(Clock::now()), prefix(prefix) {}
  easyTimer(std::string prefix, std::string suffix) : start(Clock::now()), prefix(prefix), suffix(suffix) {}
  ~easyTimer() {
    std::cout << prefix << std::chrono::duration<double, typename Unit::period>(Clock::now() - start).count()
              << deduceUnit() << suffix <<std::endl;
  }
};

#endif