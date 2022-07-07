//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_PLAYER_H
#define COMPUTERSPIEL_PLAYER_H

#include "../Entity.h"
#include "../../math/Vector.h"
#include "../../utils/Clock.h"

class Player : public Entity {
public:
    Player(const ContextWeakPtr &game, Vector pos);
    int renderLayer() const override;
    void draw() override;
    void act(float dt) override;

    Vector getPos() const;

    ~Player() override = default;
private:
    void move(float dt);
    void shoot();
    void exhaust();

    Vector pos;
    Vector vel{};

    Vector pull{};
    Vector face{};

    Clock exaustCooldown;
    Clock gunCooldown;
    float gunSide = 10;

    const float THRUST = 1000;
    const float RESISTANCE = 3;
    const float RADIUS = 30;
    const float BULLET_SPEED = 500;
};

#endif //COMPUTERSPIEL_PLAYER_H
