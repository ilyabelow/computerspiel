//
// Created by ilyabelow on 06/07/22.
//

#ifndef COMPUTERSPIEL_BUTTON_H
#define COMPUTERSPIEL_BUTTON_H

#include "../Entity.h"
#include "Plate.h"
#include "Label.h"

#include <functional>

enum State {
    INACTIVE,
    HOVERED,
    PRESSED
};

class Button : public Entity {
public:
    Button(ContextWeakPtr game, Rect rect, Point textPos, Text text, std::function<void()> callback) :
        Entity(std::move(game)),
        back(context()->add<Plate>(rect, Color(255,255,255,64))),
        callback(std::move(callback)) {
        context()->add<Label>(textPos, std::move(text));
    }

    void draw() const override {
    }

    void act(float dt) override {
        MousePtr mouse = context()->getMouse();
        if (back->getRect().inside(mouse->cursor())) {
            if (mouse->isReleased(0)) {
                callback();
            } else if (mouse->isPressed(0)) {
                if (state != PRESSED) {
                    back->changeColor(WHITE.withOpacity(100));
                    state = PRESSED;
                }
            } else {
                if (state != HOVERED) {
                    back->changeColor(WHITE.withOpacity(75));
                    state = HOVERED;
                }
            }
        } else {
            if (state != INACTIVE) {
                state = INACTIVE;
                back->changeColor(WHITE.withOpacity(50));
            }
        }
    }
    [[nodiscard]] int renderLayer() const override {
        return 1;
    }
    ~Button() override = default;
private:
    State state = INACTIVE;
    std::shared_ptr<Plate> back;
    std::function<void()> callback;
};

#endif //COMPUTERSPIEL_BUTTON_H
