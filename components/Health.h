//
// Created by ilyabelow on 08/07/22.
//

#ifndef COMPUTERSPIEL_HEALTH_H
#define COMPUTERSPIEL_HEALTH_H

#include "../entities/Entity.h"

class Health {
public:
    Health(Entity* entity, int maxHealth);
    Health(Entity* entity, int health, int maxHealth);

    [[nodiscard]] int healthLeft() const;

    void hit(int dmg);

    void heal(int up);

private:
    Entity* entity;

    int maxHealth;
    int health;
};

#endif //COMPUTERSPIEL_HEALTH_H
