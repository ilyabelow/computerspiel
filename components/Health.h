//
// Created by ilyabelow on 08/07/22.
//

#ifndef COMPUTERSPIEL_HEALTH_H
#define COMPUTERSPIEL_HEALTH_H

#include <functional>
#include "../entities/Entity.h"

class Health {
public:
    void hit(int dmg);

    void heal(int up);
protected:

    Health(int maxHealth);

    [[nodiscard]] int healthLeft() const;

private:
    int maxHealth;
    int currentHealth;

    virtual void onHealthChanged(int health, int delta) = 0;

};

#endif //COMPUTERSPIEL_HEALTH_H
