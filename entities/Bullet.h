//
// Created by ilyabelow on 05/07/2022.
//

#ifndef COMPUTERSPIEL_BULLET_H
#define COMPUTERSPIEL_BULLET_H

#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet(const GamePtr& game, Vector startPos, Vector vel);

    void draw() override;
    void act(float dt) override;
    ~Bullet() override = default;
private:

    Vector pos;
    Vector vel{};
};

#endif //COMPUTERSPIEL_BULLET_H
