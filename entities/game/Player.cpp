//
// Created by ilyabelow on 04/07/2022.
//

#include <utility>
#include "Player.h"
#include "../../Engine.h"
#include "Bullet.h"
#include "../particles/Exhaust.h"
#include "../../math/Math.h"
#include "../particles/Debris.h"

using namespace std::placeholders;

Player::Player(ContextWeakPtr game, Vector pos) :
    Entity(std::move(game)),
    Moving(pos),
    Health(100),
    Collider(this, RADIUS),
    hpLabel(context()->add<Label>(Point(10,10), Text("HP:    100", 30, WHITE))),
    invincibility(1),
    exaustCooldown(0.025),
    gunCooldown(0.2) {

}

void Player::draw() const {
    Canvas canvas = context()->getCanvas();
    float alpha = face.angle();
    Vector p1 = (pos + Vector(30, 0).rotate(alpha));
    Vector p2 = (pos + Vector(-20, -20).rotate(alpha));
    Vector p3 = (pos + Vector(-10, 0).rotate(alpha));
    Vector p4 = (pos + Vector(-20, 20).rotate(alpha));

    Color c = Color("FF0000") + WHITE.withOpacity(sqr(std::sin(invincibility.percentage()*M_PI*6))*255);
    canvas.drawLine(p1, p2, c);
    canvas.drawLine(p2, p3, c);
    canvas.drawLine(p3, p4, c);
    canvas.drawLine(p4, p1, c);
}

void Player::act(float dt) {
    move(dt, calcAcc());
    constrain();
    shoot();
    exhaust();
    exaustCooldown.tick(dt);
    gunCooldown.tick(dt);
    invincibility.tick(dt);
}

void Player::shoot() {
    MousePtr mouse = context()->getMouse();
    face = (mouse->cursor().toVector() - pos).normalize();
    if (!gunCooldown.isOver()) {
        return;
    }
    if (mouse->isPressed(0)) {
        Vector bulletPos = pos + face * (RADIUS + 20) + face.rotate(90_o);
        context()->add<Bullet>(bulletPos, face * bulletSpeed, bulletSize);
        gunCooldown.wind();
    }
}

void Player::constrain() {
    if (vel.norm2() < 1) {
        vel = Vector();
    }
    if (pos.x - RADIUS < 0) {
        pos.x = RADIUS;
        vel.x = 0;
    }
    if (pos.y - RADIUS < 0) {
        pos.y = RADIUS;
        vel.y = 0;
    }
    Point border = context()->getCanvas().rect().p2;
    if (pos.x + RADIUS > border.x) {
        pos.x = border.x - RADIUS;
        vel.x = 0;
    }
    if (pos.y + RADIUS > border.y) {
        pos.y = border.y - RADIUS;
        vel.y = 0;
    }
}

void Player::exhaust() {
    if (pull.isZero() || !exaustCooldown.isOver()) {
        return;
    }
    float radius = randomFloat(1, 10);
    float shift = randomFloat(-RADIUS / 2, RADIUS / 2);
    float speed = randomFloat(50, 100);
    Vector dir = -pull;
    if (shift > 0) {
        dir = dir.rotate(15_o);
    } else {
        dir = dir.rotate(-15_o);
    }
    Vector particlePos = pos - pull * (RADIUS + radius) + pull.rotate(90_o) * shift;
    context()->add<Exhaust>(particlePos, dir * speed, radius);
    exaustCooldown.wind();
}
int Player::renderLayer() const {
    return 5;
}
Vector Player::calcAcc() {
    pull = {};
    if (is_key_pressed(VK_DOWN)) {
        pull += {0, 1};
    }
    if (is_key_pressed(VK_UP)) {
        pull += {0, -1};
    }
    if (is_key_pressed(VK_RIGHT)) {
        pull += {1, 0};
    }
    if (is_key_pressed(VK_LEFT)) {
        pull += {-1, 0};
    }
    Vector acc{};
    if (!pull.isZero()) {
        acc += THRUST * pull.normalize();
    }
    acc -= RESISTANCE * vel;
    return acc;
}

void Player::onHealthChanged(int health, int delta) {
    if (health == 0) {
        if (context()->getGroup("you_win")[0]->isActive()) {
            return;
        }
        explode();
        context()->getGroup("game_over").activate();
        context()->getGroup("exiter").deactivate();
        disableCollider();
        die();
    } else if (delta < 0) {
        invincibility.wind();
    }
    hpLabel->changeText("HP:    " + std::to_string(health));
}

void Player::explode() {
    for (int i = 0; i < 30; i++) {
        Vector dir(randomFloat(0, M_TAUf));
        float speed = randomFloat(100, 200);
        float offset = randomFloat(0, 20);
        float time = 1 / speed * 100;
        context()->add<Debris>(pos + dir * offset, dir * speed, time);
    }
}

std::vector<std::string> Player::groupsNames() const {
    return {"player"};
}

void Player::changeGunParams(float bulletSpeedfactor, float cooldownFactor, float bulletSizeFactor) {
    bulletSpeed *= bulletSpeedfactor;
    gunCooldownSpeed *= cooldownFactor;
    bulletSize *= bulletSizeFactor;
    gunCooldown.changeTime(gunCooldownSpeed);
}

int Player::pendingHit(int dmg) {
    if (invincibility.isRunning()) {
        return 0;
    }
    return dmg;
}
