//
// Created by ilyabelow on 07/07/22.
//

#include "Enemy.h"
#include "../particles/Debris.h"
#include "../pickups/AidKit.h"
#include "../pickups/BiggerBullets.h"
#include "../pickups/FasterBullets.h"
#include "../pickups/MoreBullets.h"

Enemy::Enemy(ContextWeakPtr game, Vector pos, int health, float size, int touchDmg) :
    Enemy(std::move(game), pos, {0, 0}, health, size, touchDmg) {}

Enemy::Enemy(ContextWeakPtr game, Vector pos, Vector vel, int health, float size, int touchDmg) :
    Entity(std::move(game)),
    Moving(pos, vel),
    Collider(this, size),
    Health(health),
    player(std::dynamic_pointer_cast<Player>(context()->getGroup("player")[0])),
    hitAnimation(0.3),
    touchDmg(touchDmg),
    score(std::dynamic_pointer_cast<Score>(context()->getGroup("score")[0])){}

void Enemy::act(float dt) {
    move(dt);
    bounce();
    time += dt;
    if (player->collide(*this)) {
        player->hit(touchDmg);
    }
    hitAnimation.tick(dt);
}

int Enemy::renderLayer() const {
    return 3;
}

std::vector<std::string> Enemy::groupsNames() const {
    return {"enemy"};
}

void Enemy::onHealthChanged(int health, int delta) {
    if (health == 0) {
        onDeath();
        explode();
        generatePickup();
        addScore();
        disableCollider();
        die();
    } else if (delta < 0) {
        hitAnimation.wind();
    }

}
void Enemy::explode() {
    for (int i = 0; i < 15; i++) {
        Vector dir(randomFloat(0, M_TAUf));
        float speed = randomFloat(100, 200);
        float offset = randomFloat(0, 20);
        float time = 1 / speed * 50;
        context()->add<Debris>(pos + dir * offset, dir * speed, time);
    }
}
void Enemy::generatePickup() {
    if (randomInt(1, pickupDieSize) != 1) {
        return;
    }
    int pickupType = randomInt(1, 4);
    switch (pickupType) {
        case 1:
            context()->add<AidKit>(pos);
            break;
        case 2:
            context()->add<MoreBullets>(pos);
            break;
        case 3:
            context()->add<BiggerBullets>(pos);
            break;
        case 4:
            context()->add<FasterBullets>(pos);
            break;
    }
}
void Enemy::bounce() {
    Rect rect = context()->getCanvas().rect();
    if (pos.y < rect.p1.y + getRadius()) {
        vel.y *= -1;
        pos.y = rect.p1.y + getRadius() + EPS;
    }
    if ( pos.y > rect.p2.y - getRadius()) {
        vel.y *= -1;
        pos.y = rect.p2.y - getRadius() - EPS;
    }
    if (pos.x < rect.p1.x + getRadius()) {
        vel.x *= -1;
        pos.x = rect.p1.x + getRadius() + EPS;
    }
    if ( pos.x > rect.p2.x - getRadius()) {
        vel.x *= -1;
        pos.x = rect.p2.x - getRadius() - EPS;
    }
}

void Enemy::addScore() {
    float no_penalty = 3;
    float penalty_period = 3;
    int base_score = 50;
    if (time < no_penalty) {
        score->add(base_score);
    } else {
        score->add(base_score * std::exp(-M_LN2f*(time- no_penalty)/penalty_period));
    }
}
