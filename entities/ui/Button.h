//
// Created by ilyabelow on 06/07/22.
//

#ifndef COMPUTERSPIEL_BUTTON_H
#define COMPUTERSPIEL_BUTTON_H

#include "../Entity.h"
#include "../../utils/Types.h"

class Button : public Entity {
public:
    Button(const ContextWeakPtr &game, Point p1, Point p2, Callback&& callback);
    Button(const ContextWeakPtr &game, Point p, int w, int h, Callback&& callback);

    void draw() override;
    void act(float dt) override;
    int renderLayer() const override;
    ~Button() override = default;
private:
    Point p1;
    Point p2;
    Callback callback;
};

#endif //COMPUTERSPIEL_BUTTON_H
