//
// Created by ilyabelow on 04/07/2022.
//

#include "Math.h"

float operator ""_o(unsigned long long int x) {
    return static_cast<float>(x) / 180.f * M_PIf;
}

float operator ""_o(long double x) {
    return static_cast<float>(x) / 180.f * M_PIf;
}
float random_0_1() {
    return static_cast<float>(std::rand()) / RAND_MAX;
}
int randomInt(int from, int to) {
    return from + static_cast<int>(random_0_1() * (to - from));
}
float randomFloat(float from, float to) {
    return from + random_0_1() * (to - from);
}