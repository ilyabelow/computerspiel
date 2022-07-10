//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_BIGCIRCLE_H
#define COMPUTERSPIEL_BIGCIRCLE_H

#include "Enemy.h"

class BigCircle : public Enemy {
public:
    BigCircle(ContextWeakPtr game, Vector pos, Vector vel, int bigness, int chance) :
        Enemy(std::move(game), pos, vel, bigness * 2, bigness, bigness * 2),
        bigness(bigness) {
        pickupDieSize = chance;
    }
    BigCircle(ContextWeakPtr game, Vector pos, Vector vel, int bigness) :
        BigCircle(std::move(game), pos, vel, bigness, 3){
    }
    void draw() const override {
        context()->getCanvas().drawCircleLine(pos, bigness, "0000FF");
    }
    ~BigCircle() override = default;

private:
    void onDeath() override {
        if (bigness <= 8) {
            return;
        }
        float speed = vel.norm() * 2;
        context()->add<BigCircle>(pos, Vector(45_o) * speed, bigness / 2, pickupDieSize*2);
        context()->add<BigCircle>(pos, Vector(135_o) * speed, bigness / 2, pickupDieSize*2);
        context()->add<BigCircle>(pos, Vector(225_o) * speed, bigness / 2, pickupDieSize*2);
        context()->add<BigCircle>(pos, Vector(315_o) * speed, bigness / 2, pickupDieSize*2);
    }

    int bigness;
};

#endif //COMPUTERSPIEL_BIGCIRCLE_H
