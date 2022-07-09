//
// Created by ilyabelow on 08/07/22.
//

#include "Moving.h"

void Moving::move(float dt) {
    pos += vel * dt;
}

void Moving::move(float dt, Vector acc) {
    vel += acc * dt;
    pos += dt * vel;
}
Moving::Moving(Vector pos): pos(pos), vel() {

}
Moving::Moving(Vector pos, Vector vel): pos(pos), vel(vel) {

}
Vector Moving::getPos() {
    return pos;
}
