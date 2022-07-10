//
// Created by ilyabelow on 09/07/22.
//

#ifndef COMPUTERSPIEL_EGG_H
#define COMPUTERSPIEL_EGG_H

#include "../Entity.h"
#include "../../utils/Clock.h"
#include "Enemy.h"

class Egg : public Entity {
public:
    Egg(ContextWeakPtr game, std::shared_ptr<Enemy> enemy, float spawnTime) :
        Entity(std::move(game)),
        enemy(std::move(enemy)),
        spawn(spawnTime) {
        spawn.wind();
    }

    void draw() const override {
        context()->getCanvas().drawArc(enemy->getPos(), 10, M_PIf, M_PIf + M_TAUf * (1 - spawn.percentage()), "FFFFFF");
    }

    void act(float dt) override {
        spawn.tick(dt);
        if (spawn.isOver()) {
            die();
            context()->add(enemy);
        }
    }
    [[nodiscard]] int renderLayer() const override {
        return 3;
    }
    [[nodiscard]] std::vector<std::string> groupsNames() const override {
        return {"egg"};
    }

    ~Egg() override = default;
private:
    Clock spawn;
    std::shared_ptr<Enemy> enemy;
};

#endif //COMPUTERSPIEL_EGG_H
