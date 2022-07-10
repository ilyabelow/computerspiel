//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_MOREBULLETS_H
#define COMPUTERSPIEL_MOREBULLETS_H

#include "Pickup.h"
#include "../particles/Message.h"
#include "../control/Postponed.h"
class MoreBullets : public Pickup {
public:
    MoreBullets(ContextWeakPtr game, Vector pos) : Pickup(std::move(game), pos, "00FFFF") {}

    ~MoreBullets() override = default;
private:
    void draw(Color c) const override {
        context()->getCanvas().drawCircleLine(pos - Vector(7, 0), 5, c);
        context()->getCanvas().drawCircleLine(pos + Vector(7, 0), 5, c);
    }
    void effect() override {
        player->changeGunParams(1, .5, 1);
        context()->add<Message>(pos, "MORE BULLETS!");
        context()->add<Postponed>(
            [p = player]() {
                p->changeGunParams(1, 2, 1);
            },
            3
        );
    }

};

#endif //COMPUTERSPIEL_MOREBULLETS_H
