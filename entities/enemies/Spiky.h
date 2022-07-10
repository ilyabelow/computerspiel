//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_SPIKY_H
#define COMPUTERSPIEL_SPIKY_H

#include "Enemy.h"

class Spiky : public Enemy {
public:
    Spiky(ContextWeakPtr game, Vector pos) :
        Enemy(std::move(game), pos, 100, 30, 50) {
    }

    void draw() const override {
        Color c = Color("A04010") + WHITE.withOpacity(hitAnimation.percentageInt(255));
        Canvas canvas = context()->getCanvas();
        float size = getRadius();
        float div = 0.25*sqr(std::sin(time*5))+0.125;
        canvas.drawPolygon(pos, {
            Point(0, size),
            Point(size * div, size * div),
            Point(size, 0),
            Point(size * div, -size * div),
            Point(0, -size),
            Point(-size * div, -size * div),
            Point(-size, 0),
            Point(-size * div, size * div),
        }, c);
    }

    void act(float dt) override {
        Enemy::act(dt);
        vel = (player->getPos() - pos).normalize() * 250;
    }
    ~Spiky() override = default;
};

#endif //COMPUTERSPIEL_SPIKY_H
