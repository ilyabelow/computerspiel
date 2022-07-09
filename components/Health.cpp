//
// Created by ilyabelow on 08/07/22.
//

#include "Health.h"

Health::Health(int maxHealth) :
maxHealth(maxHealth),
currentHealth(maxHealth)
{}


int Health::healthLeft() const {
    return currentHealth;
}

void Health::hit(int dmg) {
    int prevHealth= currentHealth;
    currentHealth -= dmg;
    if (currentHealth <= 0) {
        currentHealth = 0;
    }
    onHealthChanged(currentHealth, currentHealth - prevHealth);
}

void Health::heal(int up) {
    int prevHealth = currentHealth;
    currentHealth += up;
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
    onHealthChanged(currentHealth, currentHealth - prevHealth);
}
