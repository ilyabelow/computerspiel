//
// Created by ilyabelow on 07/07/22.
//

#include "Enemy.h"
#include "../../../math/Math.h"

#include <utility>
using namespace std::placeholders;

Enemy::Enemy(ContextWeakPtr game, Vector pos, Vector vel) :
    Entity(std::move(game)),
    Moving(pos, vel),
    Health(100) {}

void Enemy::draw() const {
    context()->getCanvas().drawRotatedRectLine(pos, 30, 30, alpha, "FF00FF");
}

void Enemy::act(float dt) {
    alpha += 1/M_2_PIf*dt;
    move(dt);
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



bool Enemy::inside(const Vector &r) const {
    return (pos - r).norm2() < 1000;
}
void Enemy::onHealthChanged(int health, int delta) {
    if (health == 0) {
        die();
    }
}
