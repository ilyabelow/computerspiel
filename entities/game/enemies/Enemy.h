//
// Created by ilyabelow on 07/07/22.
//

#ifndef COMPUTERSPIEL_ENEMY_H
#define COMPUTERSPIEL_ENEMY_H

#include "../../Entity.h"
#include "../../../math/Vector.h"
#include "../../../components/Moving.h"
#include "../../../components/Health.h"

class Enemy: public Entity, public Moving, public Health {
public:
    Enemy(ContextWeakPtr game, Vector pos, Vector vel);
    [[nodiscard]] std::vector<std::string> groupsNames() const override;

    void draw() const override;
    void act(float dt) override;
    [[nodiscard]] int renderLayer() const override;
    ~Enemy() override = default;

    bool inside(const Vector& r) const;

private:
    float alpha;

    void onHealthChanged(int health, int delta) override;
};

#endif //COMPUTERSPIEL_ENEMY_H
