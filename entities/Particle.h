//
// Created by ilyabelow on 05/07/2022.
//

#ifndef COMPUTERSPIEL_PARTICLE_H
#define COMPUTERSPIEL_PARTICLE_H

#include "Entity.h"

class Particle: public Entity {
public:
    Particle(const GamePtr& game, Vector pos, Vector vel, float radius, Color color);

    void draw() override;
    void act(float dt) override;
    ~Particle() override = default;
private:
    float radius;
    float fadeSpeed;
    Color color;

    Vector pos;
    Vector vel;
};

#endif //COMPUTERSPIEL_PARTICLE_H
