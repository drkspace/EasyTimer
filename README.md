# EasyTimer
Tired of writing `std::chrono` all over the place for timing different pieces of code? Here is an easy-to-use, header file only, timer that times any code scope. 

## Example
```cpp
#include <iostream>
#include "easyTimer.hpp"
#include <thread>
#include <chrono>

int main(){

    {
        easyTimer<> t;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }

    return 0;
};
```

This will print ```Time Elapsed: 1.5s``` when `t` goes out of scope.

## Installation
Copy the [easyTimer.hpp](easyTimer.hpp) file into your source directory. **Requires C++11 or greater.**

# How to use
```cpp
easyTimer<UNIT, CLOCK> t(PREFIX, SUFFIX);
```
- `UNIT` defaults to `std::chrono::seconds` and any `std::chrono::duration` (with a representation being a double) can be used
- `CLOCK` defaults to `std::chrono::high_resolution_clock` and any [TrivialClock](https://en.cppreference.com/w/cpp/named_req/TrivialClock) can be used.
- `PREFIX` defaults to `Time Elapsed: `
- `SUFFIX` defaults to an empty string

It should be noted that there is no space between the unit abbreviation and the suffix. This was done so, if the unit abbreviation could not be found (a custom unit was used), a unit abbreviation could still be in the correct place. 

## Customization
 You can use the default implementation, which uses the unit `std::chrono::seconds` and the clock `std::chrono::high_resolution_clock`. This has the prefix `Time Elapsed: ` and has no suffix (other than the auto-detected unit abbreviation).
 ```cpp
 easyTimer<> t;
 ```

If you want to have the time reported in microseconds, you can do
```cpp
easyTimer<std::chrono::microseconds> t;
```
 
 And then if you want to use a different clock
 ```cpp
easyTimer<std::chrono::microseconds, std::chrono::steady_clock> t;
 ```
 
If you want a different prefix
```cpp
easyTimer<> t("Custom Elapsed Prefix ");
```

or custom prefix and suffix
```cpp
easyTimer<> t("Custom Elapsed Prefix ", " Custom suffix");
```
