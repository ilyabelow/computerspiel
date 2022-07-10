//
// Created by ilyabelow on 07/07/22.
//

#ifndef COMPUTERSPIEL_ENEMY_H
#define COMPUTERSPIEL_ENEMY_H

#include "../Entity.h"
#include "../game/Player.h"

#include "../../utils/Clock.h"
#include "../../math/Vector.h"
#include "../../components/Moving.h"
#include "../../components/Health.h"
#include "../../components/Collider.h"
#include "../control/Score.h"

class Enemy: public Entity, public Moving, public Health, public Collider {
public:
    Enemy(ContextWeakPtr game, Vector pos, int health, float size, int touchDmg);
    Enemy(ContextWeakPtr game, Vector pos, Vector vel, int health, float size, int touchDmg);

    [[nodiscard]] std::vector<std::string> groupsNames() const override;

    void draw() const override = 0;
    void act(float dt) override;

    [[nodiscard]] int renderLayer() const final;
    ~Enemy() override = default;
protected:
    Clock hitAnimation;
    std::shared_ptr<Player> player;
    void bounce();

    float time = 0;
    int pickupDieSize = 3;
private:
    void explode();
    void addScore();
    void onHealthChanged(int health, int delta) override;
    virtual void onDeath() {}
    void generatePickup();

    std::shared_ptr<Score> score;

    int touchDmg;
};

#endif //COMPUTERSPIEL_ENEMY_H
