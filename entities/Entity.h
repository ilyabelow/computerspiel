//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_ENTITY_H
#define COMPUTERSPIEL_ENTITY_H

#include <memory>

class Entity;

typedef std::shared_ptr<Entity> EntityPtr;
typedef std::weak_ptr<Entity> EntityWeakPtr;

#include "../core/Game.h"

class Entity {
public:
    Entity(const GamePtr& game): game(game) {}

    virtual void draw() = 0;
    virtual void act(float dt) = 0;

    bool isTrash() {
        return toTrash;
    }

    virtual ~Entity() = default;
protected:
    void trash() {
        toTrash = true;
    }
    std::shared_ptr<Game> context() {
        return game.lock();
    }

private:
    GamePtr game;

    bool toTrash = false;
};



#endif //COMPUTERSPIEL_ENTITY_H
