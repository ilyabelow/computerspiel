//
// Created by ilyabelow on 09/07/22.
//

#ifndef COMPUTERSPIEL_EGG_H
#define COMPUTERSPIEL_EGG_H

#include "../../Entity.h"
#include "../../../utils/Clock.h"
#include "Enemy.h"

class Egg: public Entity {
public:
    Egg(ContextWeakPtr game, std::shared_ptr<Enemy> enemy);

    void draw() const override;
    void act(float dt) override;
    int renderLayer() const override;
    ~Egg() override = default;
private:
    Clock spawn;
    std::shared_ptr<Enemy> enemy;
};

#endif //COMPUTERSPIEL_EGG_H
