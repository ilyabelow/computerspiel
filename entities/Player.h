//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_PLAYER_H
#define COMPUTERSPIEL_PLAYER_H

#include "Entity.h"
#include "../math/Vector.h"

class Player : public Entity {
public:
    explicit Player(GamePtr &&game, Vector pos) : Entity(std::move(game)),
                                                  pos(pos) {}

    void draw() override;
    void act(float dt) override;

    ~Player() override = default;
private:
    Vector pos;

    float thrust = 100;
    Vector vel{};
};

#endif //COMPUTERSPIEL_PLAYER_H
