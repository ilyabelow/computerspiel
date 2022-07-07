//
// Created by ilyabelow on 07/07/22.
//

#ifndef COMPUTERSPIEL_RECT_H
#define COMPUTERSPIEL_RECT_H

#include "Vector.h"
#include "Point.h"

struct Rect {
    Point p1;
    Point p2;

    Rect() = default;
    Rect(Point p1, Point p2): p1(p1), p2(p2) {}

    [[nodiscard]] bool inside(const Point& p) const {
        return p > p1 && p < p2;
    }

    [[nodiscard]] bool inside(const Vector& v) const {
        return inside(Point(static_cast<int>(v.x), static_cast<int>(v.y)));
    }
};

#endif //COMPUTERSPIEL_RECT_H
