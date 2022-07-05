//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_PLAYER_H
#define COMPUTERSPIEL_PLAYER_H

#include "Entity.h"
#include "../math/Vector.h"
#include "../utils/Clock.h"

class Player : public Entity {
public:
    Player(const GamePtr &game, Vector pos);

    void draw() override;
    void act(float dt) override;

    ~Player() override = default;
private:
    void move(float dt);
    void shoot();
    void exhaust();

    Vector pos;
    Vector vel{};
    Vector pull{};

    Clock exaustCooldown;
    Clock gunCooldown;

    const float THRUST = 1000;
    const float RESISTANCE = 3;
    const int RADIUS = 20;
};

#endif //COMPUTERSPIEL_PLAYER_H
