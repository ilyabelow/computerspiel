//
// Created by ilyabelow on 04/07/2022.
//

#include <iostream>
#include "Player.h"
#include "../Engine.h"
#include "Bullet.h"
#include "Particle.h"
#include "../math/Math.h"

Player::Player(const GamePtr &game, Vector pos) : Entity(game),
                                                  pos(pos),
                                                  exaustCooldown(0.05),
                                                  gunCooldown(0.2) {

}

void Player::draw() {
    context()->getCanvas().drawCircle(pos, RADIUS, "FF0000");
}

void Player::act(float dt) {
    move(dt);
    shoot();
    exhaust();
    exaustCooldown.tick(dt);
    gunCooldown.tick(dt);
}

void Player::shoot() {

    Vector cursor(get_cursor_x(), get_cursor_y());
    Vector dir = (cursor - pos).normalize();

    if (!gunCooldown.isOver()) {
        return;
    }
    if (is_mouse_button_pressed(0)) {
        context()->add<Bullet>(pos + dir * RADIUS, dir * 700);
        gunCooldown.reset();
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
}

void Player::exhaust() {
    if (pull.isZero() || !exaustCooldown.isOver()) {
        return;
    }
    int color = randomInt(100, 255);
    float radius = randomFloat(3, 10);
    float shift = randomFloat(-10, 10);
    Vector particlePos = pos - pull * RADIUS + pull.rotate(90_o) * shift;
    context()->add<Particle>(particlePos, -pull * 100, radius, Color(color, color, color));
    exaustCooldown.reset();
}
