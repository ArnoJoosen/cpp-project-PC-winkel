//
// Created by arno on 5/12/23.
//

#ifndef PC_WINKLE_INPUT_H
#define PC_WINKLE_INPUT_H
#include <iostream>
#include <limits>

template<typename T>
T input();

template<>
float input<float>();

template<>
int input<int>();

template<>
unsigned int input<unsigned int>();

int inputRange(int min, int max);

#endif //PC_WINKLE_INPUT_H
