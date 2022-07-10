//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_PICKUP_H
#define COMPUTERSPIEL_PICKUP_H

#include "../Entity.h"
#include "../../components/Position.h"
#include "../../math/Math.h"
#include "../game/Player.h"
#include "../../components/Collider.h"

class Pickup : public Entity, public Position, public Collider {
public:
    Pickup(ContextWeakPtr game, Vector pos, Color color) :
        Entity(std::move(game)),
        color(color),
        Position(pos),
        decay(5),
        Collider(this, 10),
        player(std::dynamic_pointer_cast<Player>(context()->getGroup("player")[0])) {
        decay.wind();
    }

    void draw() const final {
        draw(color.withOpacity(decay.percentage()*155 + (100 * sinAbove0(t*10))));
    }


    void act(float dt) final {
        decay.tick(dt);
        if (decay.isOver()) {
            die();
            return;
        }
        t += dt;
        if (player->collide(*this)) {
            effect();
            die();
        }
    }

    [[nodiscard]] int renderLayer() const final {
        return 4;
    }
    [[nodiscard]] std::vector<std::string> groupsNames() const final {
        return {"pickup"};
    }
    ~Pickup() override = default;
protected:
    virtual void draw(Color c) const = 0;

    virtual void effect() = 0;
    std::shared_ptr<Player> player;
private:
    Color color;
    Clock decay;
    float t = 0;
};

#endif //COMPUTERSPIEL_PICKUP_H
