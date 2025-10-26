#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
#include <curses.h>

void GUI() {
    std::string commands = ":q                quit application \n:t [time in s]    start timer\n:help             print commands";
    std::cout << "Welcome to tinyTimer!" << std::endl;
    std::cout << commands << std::endl;

    std::string userInput = "";
    while(true) {

        std::cout << "> ";
        std::cin >> userInput;
        if(userInput == ":q") {
            return;
        } else if (userInput == ":help") {
            std::cout << commands << std::endl;
        }
        else {
            std::cout << "Unknown command" << std::endl;
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc > 2){
        std::cout << "Give time in seconds or give no parameters to launch gui" << std::endl;
        return 0;
    } else if (argc == 1) {
        GUI();
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
    std::cout << '\a';


    return 0;
}
