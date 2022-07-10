//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_PARTICLE_H
#define COMPUTERSPIEL_PARTICLE_H

#include <utility>

#include "../Entity.h"
#include "../../components/Moving.h"
#include "../../utils/Clock.h"

class Particle : public Entity, public Moving {
public:
    Particle(ContextWeakPtr game, Vector pos, Vector vel, float lifetime) :
        Entity(std::move(game)),
        Moving(pos, vel),
        deathClock(lifetime) {
        deathClock.wind();
    }

    void draw() const override = 0;

    void act(float dt) final {
        move(dt);
        deathClock.tick(dt);
        if (deathClock.isOver()) {
            die();
        }
    }

    [[nodiscard]] int renderLayer() const final {
        return 2;
    }

    ~Particle() override = default;
protected:
    Clock deathClock;
};

#endif //COMPUTERSPIEL_PARTICLE_H
