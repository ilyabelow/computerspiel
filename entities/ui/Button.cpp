//
// Created by ilyabelow on 06/07/22.
//

#include "Button.h"

#include <utility>

Button::Button(ContextWeakPtr game, Rect rect, Callback &&callback) :
    Entity(std::move(game), rect.p1),
    rect(rect),
    callback(std::move(callback)) {}

Button::Button(ContextWeakPtr game, Point p, int w, int h, Callback &&callback) :
    Entity(std::move(game), p),
    rect(p, Point(p.x+w, p.y+h)),
    callback(std::move(callback)) {}

void Button::draw() const {
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

