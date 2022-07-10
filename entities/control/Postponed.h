//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_POSTPONED_H
#define COMPUTERSPIEL_POSTPONED_H

#include <functional>
#include <utility>
#include "NotRendered.h"
#include "../../utils/Clock.h"

class Postponed : public NotRendered {
public:
    Postponed(ContextWeakPtr game, std::function<void()> callback, float time) :
        NotRendered(std::move(game)), clock(time), callback(std::move(callback)) {
        clock.wind();
    }
    void act(float dt) override {
        clock.tick(dt);
        if (clock.isOver()) {
            callback();
            die();
        }
    }
    ~Postponed() override = default;
private:
    Clock clock;
    std::function<void()> callback;
};

#endif //COMPUTERSPIEL_POSTPONED_H
