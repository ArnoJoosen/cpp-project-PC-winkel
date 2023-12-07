//
// Created by arno on 5/12/23.
//
#include "Input.h"

template<typename T>
T input();

template<>
float input<float>() {
    std::string input;
    float num;
    bool valid = false;
    while (!valid) {
        try {
            std::getline(std::cin, input);
            num = std::stof(input);
            valid = true;
        } catch (std::exception& e) {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
    }
    return num;
}

template<>
int input<int>() {
    std::string input;
    int num;
    bool valid = false;
    while (!valid) {
        try {
            std::getline(std::cin, input);
            num = std::stoi(input);
            valid = true;
        } catch (std::exception& e) {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
    }
    return num;
}

template<>
unsigned int input<unsigned int>() {
    std::string in;
    unsigned int num;
    bool valid = false;
    while (!valid) {
        try {
            std::getline(std::cin, in);
            num = std::stoul(in);
            valid = true;
        } catch (std::exception& e) {
            std::cout << "Invalid in" << std::endl;
            continue;
        }
    }
    return num;
}

int inputRange(int min, int max) {
    int num;
    while (true) {
        num = input<int>();
        if (num < min || num > max) {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
        return num;
    }
}

bool yesNoQuestion(const char* question) {
    std::cout << question << " y or n: " << std::endl;
    std::string input;
    do {
        std::getline(std::cin, input);
        if (input == "y")
            return true;
        else if (input == "n")
            return false;
        else
            std::cout << "Invalid input. Try again: ";
    } while (input != "n");
    return false;
}