//
// Created by ilyabelow on 04/07/2022.
//

#include "Math.h"

float operator ""_o(unsigned long long int x) {
    return static_cast<float>(x) / 180.f * F_PI;
}

float operator ""_o(long double x) {
    return static_cast<float>(x) / 180.f * F_PI;
}
