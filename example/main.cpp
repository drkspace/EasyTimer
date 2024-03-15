#include <iostream>
#include "../easyTimer.hpp"
#include <thread>
#include <chrono>

int main(){

    {
        easyTimer<std::chrono::seconds> t("words ");
        std::this_thread::sleep_for(std::chrono::seconds(2));

    }

    return 0;
};