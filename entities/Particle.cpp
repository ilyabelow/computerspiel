//
// Created by ilyabelow on 05/07/2022.
//

#include "Particle.h"

Particle::Particle(const GamePtr &game, Vector pos, Vector vel, float radius, Color color) :
    Entity(game), radius(radius), pos(pos), vel(vel), color(color) {}


void Particle::draw() {
    context()->getCanvas().drawCircle(pos, radius, color);
}

void Particle::act(float dt) {
    pos += vel * dt;
    radius -= 0.1;
    if (radius <= 0.1) {
        trash();
    }
}
