//
// Created by ilyabelow on 05/07/2022.
//

#ifndef COMPUTERSPIEL_BULLET_H
#define COMPUTERSPIEL_BULLET_H

#include "../Entity.h"
#include "../../components/Moving.h"
#include "../../components/Collider.h"

class Bullet : public Entity, public Moving, public Collider {
public:
    Bullet(ContextWeakPtr game, Vector pos, Vector vel, float size);
    [[nodiscard]] int renderLayer() const override;
    void draw() const override;
    void act(float dt) override;
    ~Bullet() override = default;
private:
    float size;
    Vector dir;
};

#endif //COMPUTERSPIEL_BULLET_H
