//
// Created by ilyabelow on 04/07/2022.
//

#include "Vector.h"
#include "Math.h"

Vector::Vector(float x, float y) : x(x), y(y) {}

Vector::Vector(float phi): x(std::cos(phi)), y(std::sin(phi)) {}

Vector &Vector::operator+=(const Vector &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector Vector::operator+(const Vector &other) const {
    return Vector(x + other.x, y + other.y);
}

Vector &Vector::operator-=(const Vector &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector Vector::operator-(const Vector &other) const {
    return Vector(x - other.x, y - other.y);
}

Vector &Vector::operator*=(float c) {
    x *= c;
    y *= c;
    return *this;
}

Vector Vector::operator*(float c) const {
    return Vector(x * c, y * c);
}

Vector &Vector::operator/=(float c) {
    x /= c;
    y /= c;
    return *this;
}

Vector Vector::operator/(float c) const {
    return Vector(x / c, y / c);
}

float Vector::operator*(const Vector &other) const {
    return x*other.x + y*other.y;
}

float Vector::operator%(const Vector &other) const {
    return x*other.y - other.x*y;
}

float Vector::norm2() const {
    return x*x + y*y;
}

float Vector::norm() const {
    return std::sqrt(norm2());
}

float Vector::angle() const {
    return std::atan2(y, x);
}

Vector Vector::normalize() const {
    return *this / norm();
}

Vector Vector::rotate(float alpha) const {
    float phi = angle();
    float r = norm();
    return Vector(r*std::cos(phi+alpha), r*std::sin(phi+alpha));
}

Vector Vector::operator-() const {
    return Vector(-x, -y);
}

Vector& Vector::normalizeThis() {
    *this /= norm();
    return *this;
}

bool Vector::isZero() const {
    return std::abs(x) < EPS && std::abs(y) < EPS;
}

bool Vector::operator<(const Vector &other) const {
    return x < other.x && y < other.y;
}

bool Vector::operator>(const Vector &other) const {
    return x > other.x && y > other.y;
}
Vector::Vector(const Point &p): x(p.x), y(p.y) {

}

Vector operator*(float c, const Vector& vector) {
    return vector * c;
}

std::ostream &operator<<(std::ostream &stream, const Vector &vector) {
    stream << '{' << vector.x << ", " << vector.y << '}';
    return stream;
}
