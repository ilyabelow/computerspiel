//
// Created by ilyabelow on 06/07/22.
//

#include "Button.h"

#include <utility>
#include "../../Engine.h"

Button::Button(const ContextWeakPtr &game, Point p1, Point p2, Callback &&callback) :
    Entity(game),
    p1(p1),
    p2(p2),
    callback(std::move(callback)) {}

Button::Button(const ContextWeakPtr &game, Point p, int w, int h, Callback &&callback) :
    Entity(game),
    p1(p),
    p2(p.x+w, p.y+h),
    callback(std::move(callback)) {}

void Button::draw() {
    context()->getCanvas().drawRect(p1, p2, "FF8080");
}

void Button::act(float dt) {
    Point cursor(get_cursor_x(), get_cursor_y());
    if (cursor > p1 && cursor < p2 && is_mouse_button_pressed(0)) {
        callback();
    }
}

int Button::renderLayer() const {
    return 1;
}

