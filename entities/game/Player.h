//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_PLAYER_H
#define COMPUTERSPIEL_PLAYER_H

#include "../Entity.h"
#include "../../math/Vector.h"
#include "../../utils/Clock.h"
#include "../../components/Moving.h"
#include "../../components/Health.h"

class Player : public Entity {
public:
    Player(ContextWeakPtr game, Vector pos);
    int renderLayer() const override;
    void draw() const override;
    void act(float dt) override;

    Vector getPos() const;

    ~Player() override = default;
private:
    Vector calcAcc();
    void constrain();
    void shoot();
    void exhaust();

    Moving moving;
    Health health;

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
