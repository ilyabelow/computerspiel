//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_COLLIDER_H
#define COMPUTERSPIEL_COLLIDER_H

#include "Position.h"
#include "../math/Math.h"

class Collider {
public:
    Collider(Position *position, float radius) : position(position), radius(radius) {}

    bool collide(const Collider &other) {
        return enabled && ((position->getPos() - other.position->getPos()).norm2() < sqr(other.radius + radius));
    }
protected:
    [[nodiscard]] float getRadius() const {
        return radius;
    }
    void disableCollider() {
        enabled = false;
    }
    void enableCollider() {
        enabled = true;
    }
private:
    bool enabled = true;
    Position *position;
    float radius;
};

#endif //COMPUTERSPIEL_COLLIDER_H
