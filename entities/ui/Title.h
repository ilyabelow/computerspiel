//
// Created by ilyabelow on 09/07/22.
//

#ifndef COMPUTERSPIEL_TITLE_H
#define COMPUTERSPIEL_TITLE_H

#include <utility>

#include "../../components/Moving.h"
#include "../Entity.h"
#include "../../math/Math.h"

class Title: public Entity, public Moving {
public:
    Title(ContextWeakPtr game, Point pos):Entity(std::move(game)), Moving(pos) {}

    void draw() const override {
        Vector shiftedPos = pos + Vector(0, OSCILLATION*(1+std::sin(t)));
        context()->getCanvas().drawText(shiftedPos, "COOL AND NEW", SIZE, WHITE);
        context()->getCanvas().drawText(shiftedPos + Point(0, SIZE + BETWEEN), "GEOMETRY", SIZE * 3 / 2, WHITE);
        context()->getCanvas().drawText(shiftedPos + Point(0, SIZE + SIZE * 3 / 2 + BETWEEN * 2), "WARS", SIZE * 3, WHITE);
    }
    void act(float dt) override {
        t += dt;
    }
    int renderLayer() const override {
        return 1;
    }
    ~Title() override = default;


    static const int SIZE = 70;
    static const int BETWEEN = 10;
    static const int OSCILLATION = 10;

    static int WIDTH() { return SIZE * 12; }
    static int HEIGHT() { return BETWEEN * 2 + SIZE + SIZE * 3 + SIZE * 3 / 2 + OSCILLATION * 2; }
private:
    float t = 0;

};

#endif //COMPUTERSPIEL_TITLE_H
