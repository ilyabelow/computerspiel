//
// Created by ilyabelow on 08/07/22.
//

#ifndef COMPUTERSPIEL_MOVING_H
#define COMPUTERSPIEL_MOVING_H

#include "../math/Vector.h"

class Moving {
public:
    Vector getPos();
protected:
    explicit Moving(Vector pos);
    Moving(Vector pos, Vector vel);

    void move(float dt);

    void move(float dt, Vector acc);

    Vector vel;
    Vector pos;
};

#endif //COMPUTERSPIEL_MOVING_H
