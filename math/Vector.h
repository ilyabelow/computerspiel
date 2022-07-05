//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_VECTOR_H
#define COMPUTERSPIEL_VECTOR_H

#include <ostream>

struct Vector {
    Vector() = default;
    Vector(float x, float y);
    Vector(float phi);

    Vector& operator+=(const Vector& other);
    [[nodiscard]] Vector operator+(const Vector& other) const;
    Vector& operator-=(const Vector& other);
    [[nodiscard]] Vector operator-(const Vector& other) const;
    [[nodiscard]] Vector operator-() const;

    Vector& operator*=(float c);
    [[nodiscard]] Vector operator*(float c) const;
    Vector& operator/=(float c);
    [[nodiscard]] Vector operator/(float c) const;

    [[nodiscard]] float operator*(const Vector& other) const;
    [[nodiscard]] float operator%(const Vector& other) const;

    [[nodiscard]] bool operator<(const Vector& other) const;
    [[nodiscard]] bool operator>(const Vector& other) const;

    [[nodiscard]] float norm2() const;
    [[nodiscard]] float norm() const;
    [[nodiscard]] float angle() const;

    [[nodiscard]] Vector normalize() const;
    Vector& normalizeThis();
    [[nodiscard]] bool isZero() const;

    [[nodiscard]] Vector rotate(float alpha) const;

    float x;
    float y;
};

Vector operator*(float c, const Vector& vector);

std::ostream& operator<<(std::ostream& stream, const Vector& vector);

#endif //COMPUTERSPIEL_VECTOR_H
