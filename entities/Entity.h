//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_ENTITY_H
#define COMPUTERSPIEL_ENTITY_H

#include <memory>

class Entity;

typedef std::shared_ptr<Entity> EntityPtr;

#include "../core/Game.h"

class Entity {
public:
    Entity(GamePtr&& game): game(std::move(game)) {}

    virtual void draw() = 0;
    virtual void act(float dt) = 0;

    virtual ~Entity() = default;
protected:
    GamePtr game;
};



#endif //COMPUTERSPIEL_ENTITY_H
