//
// Created by ilyabelow on 06/07/22.
//

#ifndef COMPUTERSPIEL_LISTENER_H
#define COMPUTERSPIEL_LISTENER_H

#include <utility>

#include "../Entity.h"
#include "../../utils/Types.h"

class Listener : public Entity {
public:
    Listener(const ContextWeakPtr &game, Callback &&ear) :
        Entity(game),
        ear(std::move(ear)) {}

    void draw() override {

    }
    void act(float dt) override {
        ear();
    }
    int renderLayer() const override {
        return -1;
    }
    ~Listener() override = default;
private:
    Callback ear;
};

#endif //COMPUTERSPIEL_LISTENER_H
