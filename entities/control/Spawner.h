//
// Created by ilyabelow on 07/07/22.
//

#ifndef COMPUTERSPIEL_SPAWNER_H
#define COMPUTERSPIEL_SPAWNER_H

#include "NotRendered.h"
#include "../../utils/Clock.h"

class Spawner : public NotRendered {
public:
    explicit Spawner(ContextWeakPtr game);

    void act(float dt) override;

    ~Spawner() override = default;
private:
    void spawn();

    Clock spawnClock{};
    int iter = 0;
    int wave = 0;
    bool waveFinished = false;

    static const int wavesTotal = 4;
    constexpr static const std::array<float, wavesTotal> waveTimes = {.5,2,.2,1.5};
};

#endif //COMPUTERSPIEL_SPAWNER_H
