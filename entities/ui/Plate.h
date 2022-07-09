//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_PLATE_H
#define COMPUTERSPIEL_PLATE_H

#include "../Entity.h"

class Plate : public Entity {
public:
    Plate(ContextWeakPtr game, Rect rect, Color color) :
        Entity(std::move(game)),
        rect(rect),
        color(color) {}

    void draw() const override {
        context()->getCanvas().drawRect(rect, color);
    }
    void act(float dt) override {

    }
    [[nodiscard]] int renderLayer() const override {
        return 0;
    }

    void changeColor(Color newColor) {
        color = newColor;
    }

    Rect& getRect() {
        return rect;
    }

    ~Plate() override = default;
private:
    Rect rect;
    Color color;
};

#endif //COMPUTERSPIEL_PLATE_H
