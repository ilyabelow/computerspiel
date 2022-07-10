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
#include "../../components/Collider.h"
#include "../ui/Label.h"

class Player : public Entity, public Health, public Moving, public Collider {
public:
    Player(ContextWeakPtr game, Vector pos);
    [[nodiscard]] int renderLayer() const override;
    void draw() const override;
    void act(float dt) override;
    [[nodiscard]] std::vector<std::string> groupsNames() const override;

    ~Player() override = default;

    void changeGunParams(float bulletSpeedfactor, float cooldownFactor, float bulletSizeFactor);
private:
    Vector calcAcc();
    void constrain();
    void shoot();
    void exhaust();
    void explode();
    int pendingHit(int dmg) override;
    void onHealthChanged(int health, int delta) override;
    Vector pull{};
    Vector face{};

    Clock exaustCooldown;
    Clock gunCooldown;
    Clock invincibility;

    const float THRUST = 1000;
    const float RESISTANCE = 3;
    constexpr static const float RADIUS = 30;

    float gunCooldownSpeed = 0.2;
    float bulletSpeed = 500;
    float bulletSize = 2;

    std::shared_ptr<Label> hpLabel;
};

#endif //COMPUTERSPIEL_PLAYER_H
