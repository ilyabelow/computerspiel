//
// Created by ilyabelow on 07/07/22.
//

#include "Spawner.h"
#include "../enemies/LazySquare.h"
#include "../enemies/BigCircle.h"
#include "../enemies/Spiky.h"
#include "../enemies/Egg.h"

Spawner::Spawner(ContextWeakPtr game) :
    NotRendered(std::move(game)),
    spawnClock(waveTimes[0]) { spawnClock.wind(); }

void Spawner::act(float dt) {
    if (!waveFinished) {
        spawnClock.tick(dt);
        if (spawnClock.isOver()) {
            spawn();
        }
    } else if (context()->getGroup("enemy").empty() && context()->getGroup("egg").empty()) {
        if (wave == wavesTotal-1) {
            deactivate();
            if (context()->getGroup("game_over")[0]->isActive()) {
                return;
            }
            context()->getGroup("you_win").activate();
            context()->getGroup("exiter").deactivate();
        } else {
            iter = 0;
            wave++;
            waveFinished = false;
        }
    }
}

void Spawner::spawn() {
    if (wave == 0) {
        if (iter < 15) {
            auto enemy = context()->create<LazySquare>(
                Vector(50 + 60 * iter, 100),
                Vector(0, 200),
                "FF00FF"
            );
            context()->add<Egg>(enemy, waveTimes[0]);
            spawnClock.wind();
            iter++;
        } else {
            spawnClock.changeTime(waveTimes[1]);
            waveFinished = true;
        }
    } else if (wave == 1) {
        if (iter < 2) {
            std::shared_ptr<BigCircle> enemy = nullptr;
            if (iter == 0) {
                enemy = context()->create<BigCircle>(
                    Vector(100, 100),
                    Vector(30, 40),
                    32
                );
            }

            if (iter == 1) {
                enemy = context()->create<BigCircle>(
                    Vector(900, 700),
                    Vector(-40, -30),
                    32
                );
            }
            context()->add<Egg>(enemy, waveTimes[1]);
            spawnClock.wind();
            iter++;
        } else {
            spawnClock.changeTime(waveTimes[2]);
            waveFinished = true;
        }
    } else if (wave == 2) {
        if (iter < 20) {
            Vector dir(iter);
            Vector offset = dir * 150;
            Vector vel = dir * 250;

            auto enemy = context()->create<LazySquare>(
                Vector(500, 300)+offset,
                vel, "FF8000"
            );
            context()->add<Egg>(enemy, waveTimes[2]);
            spawnClock.wind();
            iter++;
        } else {
            spawnClock.changeTime(waveTimes[3]);
            waveFinished = true;
        }
    } else if (wave == 3) {
        if (iter < 5) {
            context()->add<Egg>(context()->create<Spiky>(
                Vector(100 + 150 * iter, 700)
            ), waveTimes[3]);
            context()->add<Egg>(context()->create<Spiky>(
                Vector(100 + 150 * iter, 100)
            ), waveTimes[3]);
            spawnClock.wind();
            iter++;
        } else {
            waveFinished = true;
        }
    }
}

