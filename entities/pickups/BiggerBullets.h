//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_BIGGERBULLETS_H
#define COMPUTERSPIEL_BIGGERBULLETS_H

#include "Pickup.h"
#include "../particles/Message.h"
#include "../control/Postponed.h"

class BiggerBullets : public Pickup {
public:
    BiggerBullets(ContextWeakPtr game, Vector pos) : Pickup(std::move(game), pos, "FFFF00") {}

    ~BiggerBullets() override = default;
private:
    void draw(Color c) const override {
        context()->getCanvas().drawCircleLine(pos, 10, c);
    }
    void effect() override {
        player->changeGunParams(1, 1, 5);
        context()->add<Message>(pos, "BIGGER BULLETS!");
        context()->add<Postponed>(
            [p = player]() {
                p->changeGunParams(1, 1, .2);
            },
            4
        );
    }

};


#endif //COMPUTERSPIEL_BIGGERBULLETS_H
