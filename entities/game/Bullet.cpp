//
// Created by ilyabelow on 05/07/2022.
//

#include "Bullet.h"
Bullet::Bullet(const ContextWeakPtr &game, Vector startPos, Vector vel) :
    Entity(game),
    pos(startPos),
    vel(vel) {}

void Bullet::act(float dt) {
    pos += vel * dt;
    if (!context()->getCanvas().rect().inside(pos)) {
        trash();
    }
}

void Bullet::draw() {
    Canvas canvas = context()->getCanvas();
    canvas.drawCircle(pos, 2, "00FF00");
    canvas.drawLine(pos, pos-vel.normalize()*20, "00FF00", 1);
}

int Bullet::renderLayer() const {
    return 7;
}
