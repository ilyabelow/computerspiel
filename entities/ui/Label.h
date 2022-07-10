//
// Created by ilyabelow on 06/07/22.
//

#ifndef COMPUTERSPIEL_LABEL_H
#define COMPUTERSPIEL_LABEL_H

#include "../Entity.h"

class Label : public Entity {
public:
    Label(ContextWeakPtr game, Point p, Text text): Entity(std::move(game)), p(p), text(std::move(text)) {}

    void draw() const override {
        context()->getCanvas().drawText(p, text);
    }

    void act(float dt) override {

    }

    void changeText(const std::string& newText) {
        text.text = newText;
    }

    [[nodiscard]] int renderLayer() const override {
        return 7;
    }
    ~Label() override = default;
private:
    Point p;
    Text text;
};

#endif //COMPUTERSPIEL_LABEL_H
