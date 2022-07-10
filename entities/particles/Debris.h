//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_DEBRIS_H
#define COMPUTERSPIEL_DEBRIS_H

#include <utility>

#include "Particle.h"

class Debris : public Particle {
public:
    Debris(ContextWeakPtr game, Vector pos, Vector vel, float lifetime) :
        Particle(std::move(game), pos, vel, lifetime) {}

    void draw() const override {
        context()->getCanvas().drawLine(pos, pos+vel/10, WHITE);
    }

    ~Debris() override = default;
};

#endif //COMPUTERSPIEL_DEBRIS_H
