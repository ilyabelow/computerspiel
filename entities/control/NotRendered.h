//
// Created by ilyabelow on 07/07/22.
//

#ifndef COMPUTERSPIEL_NOTRENDERED_H
#define COMPUTERSPIEL_NOTRENDERED_H

#include <utility>

#include "../Entity.h"

class NotRendered: public Entity {
public:
    explicit NotRendered(ContextWeakPtr game): Entity(std::move(game)) {}
    void draw() const final {

    }
    [[nodiscard]] int renderLayer() const final {
        return -1;
    }

    ~NotRendered() override = default;
};

#endif //COMPUTERSPIEL_NOTRENDERED_H
