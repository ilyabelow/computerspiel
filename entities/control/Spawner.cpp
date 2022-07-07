//
// Created by ilyabelow on 07/07/22.
//

#include "Spawner.h"
#include "../game/Enemy.h"

void Spawner::act(float dt) {
    spawn.tick(dt);
    if (spawn.isOver()) {
        if (iter < 10) {
            context()->add<Enemy>(Vector(100+90*iter,100), Vector(0,100));
            spawn.wind();
        }
        iter++;
    }
}

Spawner::Spawner(const ContextWeakPtr &game) : NotRendered(game), spawn(1) { spawn.wind(); }

