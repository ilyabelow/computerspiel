//
// Created by ilyabelow on 05/07/2022.
//

#ifndef COMPUTERSPIEL_CLOCK_H
#define COMPUTERSPIEL_CLOCK_H

#include <functional>
#include <utility>
#include <vector>

typedef std::function<void()> Callback;

class Clock {
public:
    Clock() : time(0), startTime(0) {}

    Clock( float time) : time(0), startTime(time) {}

    void tick(float dt) {
        if (time == 0) {
            return;
        }
        time -= dt;
        if (time <= 0) {
            time = 0;
        }
    }

    float timeLeft() const {
        return time;
    }

    void wind() {
        time = startTime;
    }

    void wind(float start) {
        time = start;
    }

    bool isRunning() const{
        return time > 0;
    }

    bool isOver() const{
        return time == 0;
    }

    void stop() {
        time = 0;
    }

private:
    float startTime;
    float time;
};

#endif //COMPUTERSPIEL_CLOCK_H
