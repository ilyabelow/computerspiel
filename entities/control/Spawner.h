//
// Created by ilyabelow on 07/07/22.
//

#ifndef COMPUTERSPIEL_SPAWNER_H
#define COMPUTERSPIEL_SPAWNER_H

#include "NotRendered.h"
#include "../../utils/Clock.h"

class Spawner : public NotRendered {
public:
    Spawner(ContextWeakPtr game);

    void act(float dt) override;

    ~Spawner() override = default;
private:
    Clock spawn{};
    int iter = 0;
};

#endif //COMPUTERSPIEL_SPAWNER_H
