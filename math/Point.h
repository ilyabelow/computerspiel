//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_POINT_H
#define COMPUTERSPIEL_POINT_H

struct Point;

#include "Vector.h"

struct Point {
    Point() = default;

    Point(int x, int y);

    Point(const Vector &vector);

    Vector toVector();

    bool operator<(const Point &other) const;

    bool operator>(const Point &other) const;

    [[nodiscard]] Point operator+(const Point& other) const;
    Point& operator+=(const Point& other);
    [[nodiscard]] Point operator-(const Point& other) const;
    Point& operator-=(const Point& other);

    int x;
    int y;
};

#endif //COMPUTERSPIEL_POINT_H
