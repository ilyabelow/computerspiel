//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_MESSAGE_H
#define COMPUTERSPIEL_MESSAGE_H

#include <utility>

#include "Particle.h"
#include "../../components/Moving.h"

class Message : public Particle {
public:
    Message(ContextWeakPtr game, Vector pos, const char* text) :
        Particle(std::move(game), pos, Vector(0,-50), 1), text(text, 20, WHITE) {}

    void draw() const override {
        context()->getCanvas().drawText(pos + Vector(-text.width()/2, -text.size), text);
    }

    ~Message() override = default;

private:
    Text text;
};

#endif //COMPUTERSPIEL_MESSAGE_H
