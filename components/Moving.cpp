//
// Created by ilyabelow on 08/07/22.
//

#include "Moving.h"

void Moving::move(float dt) {
    entity->pos += vel * dt;
}

void Moving::move(float dt, Vector acc) {
    vel += acc * dt;
    entity->pos += dt * vel;
}
Moving::Moving(Entity* entity): entity(entity), vel() {

}
Moving::Moving(Entity* entity, Vector vel): entity(entity), vel(vel) {

}
