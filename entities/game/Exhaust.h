//
// Created by ilyabelow on 05/07/2022.
//

#ifndef COMPUTERSPIEL_EXHAUST_H
#define COMPUTERSPIEL_EXHAUST_H

#include "../Entity.h"

class Exhaust: public Entity {
public:
    Exhaust(const ContextWeakPtr& game, Vector pos, Vector vel, float radius);

    void draw() override;
    void act(float dt) override;
    ~Exhaust() override = default;
    int renderLayer() const override;
private:
    float radius;
    float alpha = 255;

    Vector pos;
    Vector vel;
};

#endif //COMPUTERSPIEL_EXHAUST_H
