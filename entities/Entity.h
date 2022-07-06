//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_ENTITY_H
#define COMPUTERSPIEL_ENTITY_H

#include <memory>

class Entity;

typedef std::shared_ptr<Entity> EntityPtr;
typedef std::weak_ptr<Entity> EntityWeakPtr;

#include "../core/Context.h"

class Entity {
public:
    Entity(const ContextWeakPtr& game): game(game) {}

    virtual void draw() = 0;
    virtual void act(float dt) = 0;

    [[nodiscard]] virtual int renderLayer() const = 0;

    [[nodiscard]] bool isTrash() const {
        return toTrash;
    }

    virtual ~Entity() = default;
protected:
    void trash() {
        toTrash = true;
    }
    ContextPtr context() {
        return game.lock();
    }

private:
    ContextWeakPtr game;

    bool toTrash = false;
};



#endif //COMPUTERSPIEL_ENTITY_H
