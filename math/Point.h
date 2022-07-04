//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_POINT_H
#define COMPUTERSPIEL_POINT_H

#include "Vector.h"
struct Point {
    Point() = default;

    Point(int x, int y): x(x), y(y) {}

    Point(const Vector &vector) : x(static_cast<int>(vector.x)),
                                  y(static_cast<int>(vector.y)) {}

    int x;
    int y;
};

#endif //COMPUTERSPIEL_POINT_H
