//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_LAZYSQUARE_H
#define COMPUTERSPIEL_LAZYSQUARE_H

#include "Enemy.h"

class LazySquare : public Enemy {
public:
    LazySquare(ContextWeakPtr game, Vector pos, Vector startVel, Color color) :
        Enemy(std::move(game), pos, startVel, 100, 16, 25),
        color(color) {}

    void draw() const override {
        Color c = color + WHITE.withOpacity(hitAnimation.percentageInt(255));
        context()->getCanvas().drawRotatedRectLine(pos, 30, 30, 1 / M_2_PIf * time, c);
    }

    ~LazySquare() override = default;
private:
    Color color;
};

#endif //COMPUTERSPIEL_LAZYSQUARE_H
