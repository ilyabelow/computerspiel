//
// Created by ilyabelow on 05/07/2022.
//

#ifndef COMPUTERSPIEL_EXHAUST_H
#define COMPUTERSPIEL_EXHAUST_H

#include "Particle.h"
#include "../../components/Moving.h"

class Exhaust : public Particle {
public:
    Exhaust(ContextWeakPtr game, Vector pos, Vector vel, float radius) :
        Particle(std::move(game), pos, vel, 0.5), radius(radius) {}

    void draw() const override {
        float newRadius = radius + 20*deathClock.timeLeft();
        auto alpha = static_cast<uint8_t>(255*deathClock.timeLeft());

        context()->getCanvas().drawCircleInside(pos,
                                                newRadius,
                                                Color("FFFFFF", alpha));
    }

    ~Exhaust() override = default;

private:
    float radius;
};

#endif //COMPUTERSPIEL_EXHAUST_H
