//
// Created by ilyabelow on 07/07/22.
//

#include "Spawner.h"

#include <utility>
#include "../game/enemies/Enemy.h"
#include "../game/enemies/Egg.h"

void Spawner::act(float dt) {
    spawn.tick(dt);
    if (spawn.isOver()) {
        if (iter < 10) {
            auto enemy = context()->create<Enemy>(Vector(100+90*iter,100), Vector(0,100));
            context()->add<Egg>(enemy);
            spawn.wind();
        }
        iter++;
    }
}

Spawner::Spawner(ContextWeakPtr game) : NotRendered(std::move(game)), spawn(1) { spawn.wind(); }

