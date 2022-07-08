//
// Created by ilyabelow on 08/07/22.
//

#ifndef COMPUTERSPIEL_MOVING_H
#define COMPUTERSPIEL_MOVING_H

#include "../math/Vector.h"
#include "../entities/Entity.h"

class Moving {
public:
    explicit Moving(Entity* entity);
    Moving(Entity* entity, Vector vel);

    void move(float dt);

    void move(float dt, Vector acc);

    Entity* entity;
    Vector vel;
};

#endif //COMPUTERSPIEL_MOVING_H
