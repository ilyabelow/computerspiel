//
// Created by ilyabelow on 06/07/22.
//

#include "Button.h"

#include <utility>
#include "../../Engine.h"

Button::Button(const ContextWeakPtr &game, Rect rect, Callback &&callback) :
    Entity(game),
    rect(rect),
    callback(std::move(callback)) {}

Button::Button(const ContextWeakPtr &game, Point p, int w, int h, Callback &&callback) :
    Entity(game),
    rect(p, Point(p.x+w, p.y+h)),
    callback(std::move(callback)) {}

void Button::draw() {
    context()->getCanvas().drawRect(rect, "FF8080");
}

void Button::act(float dt) {
    MousePtr mouse = context()->getMouse();
    if (rect.inside(mouse->cursor()) && mouse->isClicked(0)) {
        mouse->freeze(0);
        callback();
    }
}

int Button::renderLayer() const {
    return 1;
}

