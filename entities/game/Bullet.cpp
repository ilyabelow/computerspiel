//
// Created by ilyabelow on 05/07/2022.
//

#include "Bullet.h"

#include <utility>
#include "enemies/Enemy.h"

Bullet::Bullet(ContextWeakPtr game, Vector pos, Vector vel) :
    Entity(std::move(game)), Moving(pos, vel) {}

void Bullet::act(float dt) {
    move(dt);
    if (!context()->getCanvas().rect().inside(pos)) {
        die();
    }
    auto & enemies = context()->getGroup("enemy");
    for (auto & enemyEntity: enemies) {
        auto enemy = std::dynamic_pointer_cast<Enemy>(enemyEntity);
        if (enemy->inside(pos)) {
            enemy->hit(50);
            die();
        }
    }
}

void Bullet::draw() const {
    Canvas canvas = context()->getCanvas();
    canvas.drawCircleInside(pos, 2, "00FF00");
    canvas.drawLine(pos, pos - vel.normalize() * 20, "00FF00");
}

int Bullet::renderLayer() const {
    return 7;
}
