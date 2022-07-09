//
// Created by ilyabelow on 04/07/2022.
//

#include <iostream>
#include <utility>
#include "Player.h"
#include "../../Engine.h"
#include "Bullet.h"
#include "Exhaust.h"
#include "../../math/Math.h"

using namespace std::placeholders;

Player::Player(ContextWeakPtr game, Vector pos) : Entity(std::move(game)),
                                                  Moving(pos),
                                                  Health(100),
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

    canvas.drawLine(p1, p2, "FF0000");
    canvas.drawLine(p2, p3, "FF0000");
    canvas.drawLine(p3, p4, "FF0000");
    canvas.drawLine(p4, p1, "FF0000");
}

void Player::act(float dt) {
    move(dt, calcAcc());
    constrain();
    shoot();
    exhaust();

    exaustCooldown.tick(dt);
    gunCooldown.tick(dt);
}

void Player::shoot() {
    MousePtr mouse = context()->getMouse();
    face = (mouse->cursor().toVector() - pos).normalize();
    if (!gunCooldown.isOver()) {
        return;
    }
    if (mouse->isPressed(0)) {
        Vector bulletPos = pos + face * (RADIUS + 20) + face.rotate(90_o);
        context()->add<Bullet>(bulletPos, face * BULLET_SPEED);
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
        die();
    }
}
