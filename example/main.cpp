#include <iostream>
#include "../easyTimer.hpp"
#include <thread>
#include <chrono>

int main(){

    {
        easyTimer<std::chrono::seconds> t("Custom Elapsed Prefix ");
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        // Will print "Custom Elapsed Prefix 1.5s"
    }

    return 0;
};