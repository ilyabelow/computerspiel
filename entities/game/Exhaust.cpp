//
// Created by ilyabelow on 05/07/2022.
//

#include "Exhaust.h"

#include <utility>

Exhaust::Exhaust(ContextWeakPtr game, Vector pos, Vector vel, float radius) :
    Entity(std::move(game)), Moving(pos, vel), radius(radius) {}


void Exhaust::draw() const {
    context()->getCanvas().drawCircleInside(pos,
                                            radius,
                                            Color("FFFFFF", static_cast<uint8_t>(alpha)));
}

void Exhaust::act(float dt) {
    move(dt);
    radius += 20 * dt;
    alpha -= 500 * dt;
    if (alpha <= 0.1) {
        die();
    }
}
int Exhaust::renderLayer() const {
    return 3;
}
