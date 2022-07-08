//
// Created by ilyabelow on 05/07/2022.
//

#ifndef COMPUTERSPIEL_BULLET_H
#define COMPUTERSPIEL_BULLET_H

#include "../Entity.h"
#include "../../components/Moving.h"

class Bullet : public Entity {
public:
    Bullet(ContextWeakPtr game, Vector startPos, Vector vel);
    int renderLayer() const override;
    void draw() const override;
    void act(float dt) override;
    ~Bullet() override = default;
private:
    Moving moving;
};

#endif //COMPUTERSPIEL_BULLET_H
