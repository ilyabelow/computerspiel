//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_MATH_H
#define COMPUTERSPIEL_MATH_H

#include <cmath>

#define F_PI 3.14159265358979323846f
#define EPS 0.00001

float operator ""_o(unsigned long long int x);

float operator ""_o(long double x);

template <typename T>
T sqr(T x) {
    return x*x;
}

#endif //COMPUTERSPIEL_MATH_H
