//
// Created by ilyabelow on 07/07/22.
//

#include "Enemy.h"

void Enemy::draw() {
    context()->getCanvas().drawRect(pos, 30, 30, "FF00FF");
}

void Enemy::act(float dt) {
    pos += vel * dt;
    if (!context()->getCanvas().rect().inside(pos)) {
        trash();
    }
}

int Enemy::renderLayer() const {
    return 3;
}

Enemy::Enemy(const ContextWeakPtr& game, Vector pos, Vector vel): Entity(game), pos(pos), vel(vel) {

}
