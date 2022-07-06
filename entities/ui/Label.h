//
// Created by ilyabelow on 06/07/22.
//

#ifndef COMPUTERSPIEL_LABEL_H
#define COMPUTERSPIEL_LABEL_H

#include "../Entity.h"

class Label : public Entity {
public:
    Label(const ContextWeakPtr &game, Point p, int w, int h);
    Label(const ContextWeakPtr &game, Point p, int w, int h, Color c);

    void draw() override;
    void act(float dt) override;
    [[nodiscard]] int renderLayer() const override;
    ~Label() override = default;
private:
    Point p1;
    Point p2;
    Color color;
};

#endif //COMPUTERSPIEL_LABEL_H
