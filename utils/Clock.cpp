//
// Created by ilyabelow on 10/07/22.
//

#include "Clock.h"

Clock::Clock() : time(0), startTime(0) {}

Clock::Clock(float time) : time(0), startTime(time) {}

void Clock::tick(float dt) {
    if (time == 0) {
        return;
    }
    time -= dt;
    if (time <= 0) {
        time = 0;
    }
}

float Clock::timeLeft() const {
    return time;
}

float Clock::timeTotal() const {
    return startTime;
}

float Clock::percentage() const {
    return time / startTime;
}

int Clock::percentageInt(int multiplier) const {
    return static_cast<int>(percentage() * multiplier);
}

void Clock::wind() {
    time = startTime;
}

bool Clock::isRunning() const {
    return time > 0;
}

bool Clock::isOver() const {
    return time == 0;
}

void Clock::stop() {
    time = 0;
}

void Clock::changeTime(float start) {
    startTime = start;
}
