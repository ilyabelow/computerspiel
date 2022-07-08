//
// Created by ilyabelow on 05/07/2022.
//

#include "Bullet.h"

#include <utility>
#include "Enemy.h"

Bullet::Bullet(ContextWeakPtr game, Vector startPos, Vector vel) :
    Entity(std::move(game), startPos), moving(this, vel) {}

void Bullet::act(float dt) {
    moving.move(dt);
    if (!context()->getCanvas().rect().inside(pos)) {
        die();
    }
    auto & enemies = context()->getGroup("enemy");
    for (auto & enemy: enemies) {
        if (std::dynamic_pointer_cast<Enemy>(enemy)->inside(pos)) {
            enemy->die();
            die();
        }
    }
}

void Bullet::draw() const {
    Canvas canvas = context()->getCanvas();
    canvas.drawCircle(pos, 2, "00FF00");
    canvas.drawLine(pos, pos-moving.vel.normalize()*20, "00FF00", 1);
}

int Bullet::renderLayer() const {
    return 7;
}
