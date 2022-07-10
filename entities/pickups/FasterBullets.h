//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_FASTERBULLETS_H
#define COMPUTERSPIEL_FASTERBULLETS_H

#include "Pickup.h"
#include "../particles/Message.h"
#include "../control/Postponed.h"

class FasterBullets : public Pickup {
public:
    FasterBullets(ContextWeakPtr game, Vector pos) : Pickup(std::move(game), pos, "FF00FF") {}

    ~FasterBullets() override = default;
private:
    void draw(Color c) const override {
        Canvas canvas = context()->getCanvas();
        canvas.drawCircleLine(pos - Vector(0, 7), 4, c);
        canvas.drawLine(pos + Vector(0, 3), pos+Vector(0,10), c);
        canvas.drawLine(pos + Vector(4, 2), pos+Vector(6,8), c);
        canvas.drawLine(pos + Vector(-4, 2), pos+Vector(-6,8), c);

    }
    void effect() override {
        player->changeGunParams(2, 1, 1);
        context()->add<Message>(pos, "FASTER BULLETS!");
        context()->add<Postponed>(
            [p = player]() {
                p->changeGunParams(0.5, 1, 1);
            },
            5
        );
    }
};


#endif //COMPUTERSPIEL_FASTERBULLETS_H
