//
// Created by ilyabelow on 08/07/22.
//

#include "Health.h"

Health::Health(Entity* entity, int maxHealth) :
    entity(entity),
    maxHealth(maxHealth),
    health(maxHealth) {}

Health::Health(Entity* entity, int health, int maxHealth) :
    entity(entity),
    maxHealth(maxHealth),
    health(health) { }

int Health::healthLeft() const {
    return health;
}

void Health::hit(int dmg) {
    health -= dmg;
    if (health <= 0) {
        entity->die();
    }
}
void Health::heal(int up) {
    health += up;
    if (health > maxHealth) {
        health = maxHealth;
    }
}
