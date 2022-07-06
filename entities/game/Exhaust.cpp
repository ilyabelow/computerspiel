//
// Created by ilyabelow on 05/07/2022.
//

#include "Exhaust.h"

Exhaust::Exhaust(const ContextWeakPtr &game, Vector pos, Vector vel, float radius) :
    Entity(game), radius(radius), pos(pos), vel(vel){}


void Exhaust::draw() {
    context()->getCanvas().drawCircle(pos,
                                      radius,
                                      Color("FFFFFF", static_cast<uint8_t>(alpha)));
}

void Exhaust::act(float dt) {
    pos += vel * dt;
    radius += 20 * dt;
    alpha -= 500 * dt;
    if (alpha <= 0.1) {
        trash();
    }
}
int Exhaust::renderLayer() const {
    return 3;
}
