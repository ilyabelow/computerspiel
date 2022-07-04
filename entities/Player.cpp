//
// Created by ilyabelow on 04/07/2022.
//

#include "Player.h"
#include "../Engine.h"

void Player::draw() {
    game.lock()->getCanvas().drawCircle(pos, 15, "FF0000");
}

void Player::act(float dt) {
    Vector acc{};
    if (is_key_pressed(VK_DOWN)) {
        acc += {1, 0};
    }
    if (is_key_pressed(VK_UP)) {
        acc += {-1, 0};
    }
    if (is_key_pressed(VK_RIGHT)) {
        acc += {0, 1};
    }
    if (is_key_pressed(VK_LEFT)) {
        acc += {0, -1};
    }
    if (!acc.isZero()) {
        acc.normalizeThis();
        vel += thrust * dt * acc;
    }
    pos += dt * vel;
}

