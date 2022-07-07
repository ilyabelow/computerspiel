//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_MATH_H
#define COMPUTERSPIEL_MATH_H

#include <cmath>
#include <cstdlib>

#define EPS 0.00001

float operator ""_o(unsigned long long int x);

float operator ""_o(long double x);

float random_0_1();

int randomInt(int from, int to);

float randomFloat(float from, float to);

template <typename T>
T sqr(T x) {
    return x*x;
}

#endif //COMPUTERSPIEL_MATH_H
