//
// Created by ilyabelow on 05/07/2022.
//

#include "Bullet.h"

#include <utility>
#include "../enemies/Enemy.h"

Bullet::Bullet(ContextWeakPtr game, Vector pos, Vector vel, float size) :
    Entity(std::move(game)),
    Moving(pos, vel),
    Collider(this, size),
    size(size),
    dir(vel.normalize()){}

void Bullet::act(float dt) {
    move(dt);
    if (!context()->getCanvas().rect().inside(pos)) {
        die();
    }
    auto & enemies = context()->getGroup("enemy");
    for (int i = 0; i < enemies.size(); i++) {
        auto enemy = std::dynamic_pointer_cast<Enemy>(enemies[i]);
        if (enemy->collide(*this)) {
            enemy->hit(50);
            die();
        }
    }
}

void Bullet::draw() const {
    Canvas canvas = context()->getCanvas();
    canvas.drawCircleInside(pos, size, "00FF00");
    canvas.drawLine(pos, pos - dir * 20, "00FF00");
}

int Bullet::renderLayer() const {
    return 7;
}
