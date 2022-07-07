//
// Created by ilyabelow on 07/07/22.
//

#ifndef COMPUTERSPIEL_ENEMY_H
#define COMPUTERSPIEL_ENEMY_H

#include "../Entity.h"
#include "../../math/Vector.h"

class Enemy: public Entity {
public:
    Enemy(const ContextWeakPtr& game, Vector pos, Vector vel);

    void draw() override;
    void act(float dt) override;
    [[nodiscard]] int renderLayer() const override;
    ~Enemy() override = default;
private:
    Vector pos;
    Vector vel;
};

#endif //COMPUTERSPIEL_ENEMY_H
