//
// Created by ilyabelow on 08/07/22.
//

#ifndef COMPUTERSPIEL_HEALTH_H
#define COMPUTERSPIEL_HEALTH_H

#include <functional>
#include "../entities/Entity.h"

class Health {
public:
    void hit(int dmg) {
        dmg = pendingHit(dmg);
        if (dmg == 0) {
            return;
        }
        int prevHealth = currentHealth;
        currentHealth -= dmg;
        if (currentHealth <= 0) {
            currentHealth = 0;
        }
        onHealthChanged(currentHealth, currentHealth - prevHealth);
    }

    void heal(int up) {
        up = pendingHeal(up);
        if (up == 0) {
            return;
        }
        int prevHealth = currentHealth;
        currentHealth += up;
        if (currentHealth > maxHealth) {
            currentHealth = maxHealth;
        }
        onHealthChanged(currentHealth, currentHealth - prevHealth);
    }
protected:

    Health(int maxHealth) : currentHealth(maxHealth), maxHealth(maxHealth) {}

    [[nodiscard]] int healthLeft() const {
        return currentHealth;
    }

private:
    int maxHealth;
    int currentHealth;

    virtual void onHealthChanged(int health, int delta) = 0;
    virtual int pendingHit(int dmg) { return dmg; }
    virtual int pendingHeal(int up) { return up; }
};

#endif //COMPUTERSPIEL_HEALTH_H
