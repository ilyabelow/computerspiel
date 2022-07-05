//
// Created by ilyabelow on 05/07/2022.
//

#include "Bullet.h"
Bullet::Bullet(const GamePtr &game, Vector startPos, Vector vel) :
    Entity(game),
    pos(startPos),
    vel(vel) {}

void Bullet::act(float dt) {
    pos += vel * dt;
    if (pos < context()->upLeftCorner || pos > context()->downRightCorner) {
        trash();
    }
}

void Bullet::draw() {
    context()->getCanvas().drawCircle(pos, 5, "00FF00");
}
