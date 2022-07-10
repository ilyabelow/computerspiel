//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_AIDKIT_H
#define COMPUTERSPIEL_AIDKIT_H

#include "Pickup.h"
#include "../particles/Message.h"

class AidKit: public Pickup {
public:
    AidKit(ContextWeakPtr game, Vector pos):
    Pickup(std::move(game), pos, "FF8080"),
    outline( {{size/3, 0},
            {2*size/3, 0},
            {2*size/3, size/3},
            {size, size/3},
            {size, 2*size/3},
            {2*size/3, 2*size/3},
            {2*size/3, size},
            {size/3, size},
            {size/3, 2*size/3},
            {0, 2*size/3},
            {0, size/3},
            {size/3, size/3},
            }) {}
    ~AidKit() override = default;

protected:
    void effect() override {
        player->heal(25);
        context()->add<Message>(pos, "+25 HEALTH");
    }
    void draw(Color c) const override {
        context()->getCanvas().drawPolygon(pos-Vector(size/2, size/2), outline, c);
    }
    static const int size = 15;
private:
    std::vector<Point> outline;
};

#endif //COMPUTERSPIEL_AIDKIT_H
