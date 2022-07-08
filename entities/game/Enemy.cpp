//
// Created by ilyabelow on 07/07/22.
//

#include "Enemy.h"

#include <utility>

void Enemy::draw() const {
    context()->getCanvas().drawRect(pos, 30, 30, "FF00FF");
}

void Enemy::act(float dt) {
    moving.move(dt);
    if (!context()->getCanvas().rect().inside(pos)) {
        die();
    }
}

int Enemy::renderLayer() const {
    return 3;
}

std::vector<std::string> Enemy::groupsNames() const {
    return {"enemy"};
}

Enemy::Enemy(ContextWeakPtr game, Vector pos, Vector vel) :
    Entity(std::move(game), pos),
    moving(this, vel),
    health(this, 100) {}
bool Enemy::inside(const Vector &r) const {
    return (pos - r).norm2() < 1000;
}
