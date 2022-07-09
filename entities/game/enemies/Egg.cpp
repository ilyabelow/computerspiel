//
// Created by ilyabelow on 09/07/22.
//

#include "Egg.h"
#include "../../../math/Math.h"

#include <utility>


Egg::Egg(ContextWeakPtr game, std::shared_ptr<Enemy> enemy) :
    Entity(std::move(game)),
    enemy(std::move(enemy)),
    spawn(1) {
    spawn.wind();
}

void Egg::draw() const {
    context()->getCanvas().drawArc(
        enemy->getPos(),
        10,
        M_PIf,
        M_PIf + M_TAUf * (1 - spawn.timeLeft()),
        "FFFFFF");
}

void Egg::act(float dt) {
    spawn.tick(dt);
    if (spawn.isOver()) {
        die();
        context()->add(enemy);
    }
}

int Egg::renderLayer() const {
    return 3;
}
