//
// Created by ilyabelow on 06/07/22.
//

#include "Label.h"

Label::Label(ContextWeakPtr game, Point p, int w, int h, Color c) :
    Entity(std::move(game), p),
    p1(p),
    p2(p.x + w, p.y + h),
    color(c) {}
Label::Label(ContextWeakPtr game, Point p, int w, int h) :
    Label(std::move(game), p, w, h, "80FF80") {}

void Label::draw() const {
    context()->getCanvas().drawRect(p1, p2, color);
}

void Label::act(float dt) {

}

int Label::renderLayer() const {
    return 0;
}

