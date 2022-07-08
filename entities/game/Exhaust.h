//
// Created by ilyabelow on 05/07/2022.
//

#ifndef COMPUTERSPIEL_EXHAUST_H
#define COMPUTERSPIEL_EXHAUST_H

#include "../Entity.h"
#include "../../components/Moving.h"

class Exhaust: public Entity {
public:
    Exhaust(ContextWeakPtr game, Vector pos, Vector vel, float radius);

    void draw() const override;
    void act(float dt) override;
    ~Exhaust() override = default;
    int renderLayer() const override;
private:
    Moving moving;

    float radius;
    float alpha = 255;
};

#endif //COMPUTERSPIEL_EXHAUST_H
