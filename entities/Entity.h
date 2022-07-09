//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_ENTITY_H
#define COMPUTERSPIEL_ENTITY_H

#include <memory>
#include <utility>

class Entity;

typedef std::shared_ptr<Entity> EntityPtr;
typedef std::weak_ptr<Entity> EntityWeakPtr;

#include "../core/Context.h"

class Entity {
public:
    explicit Entity(ContextWeakPtr game): game(std::move(game)) {}

    virtual void draw() const = 0;
    virtual void act(float dt) = 0;

    [[nodiscard]] virtual int renderLayer() const = 0;
    [[nodiscard]] virtual std::vector<std::string> groupsNames() const {
        return {};
    };

    [[nodiscard]] bool isZombie() const {
        return zombie;
    }
    void die() {
        zombie = true;
    }

    virtual ~Entity() = default;
protected:
    [[nodiscard]] ContextPtr context() const {
        return game.lock();
    }
private:
    ContextWeakPtr game;

    bool zombie = false;
};



#endif //COMPUTERSPIEL_ENTITY_H
