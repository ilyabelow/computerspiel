//
// Created by ilyabelow on 08/07/22.
//

#ifndef COMPUTERSPIEL_MOVING_H
#define COMPUTERSPIEL_MOVING_H

#include "../math/Vector.h"
#include "Position.h"

class Moving: public Position {

protected:
    explicit Moving(Vector pos) : Position(pos), vel() {

    }
    Moving(Vector pos, Vector vel): Position(pos), vel(vel) {

    }

    void move(float dt) {
        pos += vel * dt;
    }

    void move(float dt, Vector acc){
        vel += acc * dt;
        pos += dt * vel;
    }

    Vector vel;
};

#endif //COMPUTERSPIEL_MOVING_H
