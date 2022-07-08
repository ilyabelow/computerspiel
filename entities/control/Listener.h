//
// Created by ilyabelow on 06/07/22.
//

#ifndef COMPUTERSPIEL_LISTENER_H
#define COMPUTERSPIEL_LISTENER_H

#include <utility>

#include "NotRendered.h"
#include "../../utils/Types.h"

class Listener : public NotRendered {
public:
    Listener(ContextWeakPtr game, Callback ear) :
        NotRendered(std::move(game)),
        ear(std::move(ear)) {}

    void act(float dt) override {
        ear();
    }
    ~Listener() override = default;
private:
    Callback ear;
};

#endif //COMPUTERSPIEL_LISTENER_H
