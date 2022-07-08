//
// Created by ilyabelow on 07/07/22.
//

#ifndef COMPUTERSPIEL_BACKGROUND_H
#define COMPUTERSPIEL_BACKGROUND_H

#include "../Entity.h"
#include "Player.h"


struct Star {
    Star() = default;
    Star(Vector pos, Vector vel, int radius, Color color);

    Vector pos;
    Vector vel;
    float radius;
    Color color;
};


class Background: public Entity {
public:
    Background(ContextWeakPtr game, std::shared_ptr<Player> player);

    void draw() const override;
    void act(float dt) override;
    int renderLayer() const override;
    ~Background() override = default;
private:
    const int F_SHIFT = 8;
    const int B_SHIFT = 16;

    std::shared_ptr<Player> player;
    Rect frontRect{};
    Rect backRect{};

    std::vector<Star> backStars{};
    std::vector<Star> frontStars{};
};

#endif //COMPUTERSPIEL_BACKGROUND_H
