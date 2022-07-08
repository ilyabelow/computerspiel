//
// Created by ilyabelow on 06/07/22.
//

#ifndef COMPUTERSPIEL_BUTTON_H
#define COMPUTERSPIEL_BUTTON_H

#include "../Entity.h"
#include "../../utils/Types.h"

class Button : public Entity {
public:
    Button(ContextWeakPtr game, Rect rect, Callback&& callback);
    Button(ContextWeakPtr game, Point p, int w, int h, Callback&& callback);

    void draw() const override;
    void act(float dt) override;
    int renderLayer() const override;
    ~Button() override = default;
private:
    Rect rect;
    Callback callback;
};

#endif //COMPUTERSPIEL_BUTTON_H
