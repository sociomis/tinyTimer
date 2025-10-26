#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>


int main(int argc, char* argv[])
{
    if (argc != 2){
        std::cout << "Give one parameter, time in seconds!" << std::endl;
        return 0;
    }

    int seconds = std::stoi(argv[1]);
    int minutes = 0;
    if (seconds > 59) {
        minutes = seconds / 60;
        seconds = seconds % 60;
    }

    while (seconds >= 1) {
        std::cout << std::format("{:02}", minutes) << ":" << std::format("{:02}", seconds) << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (seconds == 1 && minutes > 0) {
            seconds--;
            std::cout << std::format("{:02}", minutes) << ":" << std::format("{:02}", seconds) << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));

            seconds = 59;
            minutes--;
        } else {
            seconds--;
        }
        }
    std::cout << "Times up!" << std::endl;


    return 0;
}
