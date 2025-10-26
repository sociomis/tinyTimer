#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
#include <curses.h>


int main(int argc, char* argv[])
{
    if (argc != 2){
        std::cout << "Give one parameter, time in seconds!" << std::endl;
        return 0;
    }
    int seconds;
    try {
        seconds = std::stoi(argv[1]);
    }
    catch (std::invalid_argument& e) {
        std::cout << "Error with input: " << e.what() << std::endl;
        return -1;
    }

    int minutes = 0;
    if (seconds > 59) {
        minutes = seconds / 60;
        seconds = seconds % 60;
    }

    while (seconds >= 1) {
        std::cout << "Time remaining: " << std::format("{:02}", minutes) << ":" << std::format("{:02}", seconds) << '\r';
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (seconds == 1 && minutes > 0) {
            seconds--;
            std::cout << std::format("{:02}", minutes) << ":" << std::format("{:02}", seconds) << '\r';// << std::endl;
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::seconds(1));

            seconds = 59;
            minutes--;
        } else {
            seconds--;
        }
        }
    std::cout << "\nTimes up!" << std::endl;


    return 0;
}
