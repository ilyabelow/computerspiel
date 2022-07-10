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
    int dist = to-from+1;
    int rem = std::rand() % dist;
    return from + rem;
}
float randomFloat(float from, float to) {
    return from + random_0_1() * (to - from);
}
float atan2bound(float y, float x) {
    float phi = std::atan2(y, x);
    if (phi < 0) {
        phi += M_TAUf;
    }
    return phi;
}
float sinAbove0(float x) {
    return (1 + std::sin(x)) / 2;
}
