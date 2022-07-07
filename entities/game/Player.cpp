//
// Created by ilyabelow on 04/07/2022.
//

#include <iostream>
#include "Player.h"
#include "../../Engine.h"
#include "Bullet.h"
#include "Exhaust.h"
#include "../../math/Math.h"

Player::Player(const ContextWeakPtr &game, Vector pos) : Entity(game),
                                                         pos(pos),
                                                         exaustCooldown(0.025),
                                                         gunCooldown(0.2) {}

void Player::draw() {
    Canvas canvas = context()->getCanvas();
    float angle = pull.angle() + M_PIf;
    canvas.drawCircleLine(pos, RADIUS, "FF0000", 1);
    Vector offset = std::abs(gunSide) * face.rotate(90_o);
    canvas.drawLine(pos+face*RADIUS+offset, pos+face*(RADIUS+10)+offset, "FF0000", 1);
    canvas.drawLine(pos+face*RADIUS-offset, pos+face*(RADIUS+10)-offset, "FF0000", 1);

}

void Player::act(float dt) {
    move(dt);
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
        Vector bulletPos = pos + face * (RADIUS +20)+ gunSide * face.rotate(90_o);
        gunSide = -gunSide;
        context()->add<Bullet>(bulletPos, face * BULLET_SPEED);
        gunCooldown.wind();
    }
}

void Player::move(float dt) {
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
    vel += acc * dt;
    if (vel.norm2() < 1) {
        vel = Vector();
    }
    pos += dt * vel;

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
Vector Player::getPos() const {
    return pos;
}
