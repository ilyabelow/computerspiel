//
// Created by ilyabelow on 07/07/22.
//

#include "Point.h"
Point::Point(const Vector &vector) : x(static_cast<int>(vector.x)),
                                     y(static_cast<int>(vector.y)) {}
Vector Point::toVector() {
    return *this;
}
bool Point::operator<(const Point &other) const {
    return x < other.x && y < other.y;
}
bool Point::operator>(const Point &other) const {
    return x > other.x && y > other.y;
}
Point::Point(int x, int y) : x(x), y(y) {}

Point Point::operator+(const Point &other) const {
    return {x+other.x, y+other.y};
}
Point &Point::operator+=(const Point &other) {
    x += other.x;
    y += other.y;
    return *this;
}
Point Point::operator-(const Point &other) const {
    return {x-other.x, y-other.y};
}
Point &Point::operator-=(const Point &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}
