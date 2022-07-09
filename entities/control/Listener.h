//
// Created by ilyabelow on 06/07/22.
//

#ifndef COMPUTERSPIEL_LISTENER_H
#define COMPUTERSPIEL_LISTENER_H

#include <utility>

#include "NotRendered.h"

class Listener : public NotRendered {
public:
    Listener(ContextWeakPtr game, std::function<void()> ear) :
        NotRendered(std::move(game)),
        ear(std::move(ear)) {}

    void act(float dt) override {
        ear();
    }
    ~Listener() override = default;
private:
    std::function<void()> ear;
};

#endif //COMPUTERSPIEL_LISTENER_H
