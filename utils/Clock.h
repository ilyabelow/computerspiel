//
// Created by ilyabelow on 05/07/2022.
//

#ifndef COMPUTERSPIEL_CLOCK_H
#define COMPUTERSPIEL_CLOCK_H

class Clock {
public:
    Clock();

    explicit Clock(float time);

    void tick(float dt);

    [[nodiscard]] float timeLeft() const;

    [[nodiscard]] float timeTotal() const;

    [[nodiscard]] float percentage() const;

    [[nodiscard]] int percentageInt(int multiplier) const;

    void wind();

    void changeTime(float start);

    [[nodiscard]] bool isRunning() const;

    [[nodiscard]] bool isOver() const;

    void stop();

private:
    float startTime;
    float time;
};

#endif //COMPUTERSPIEL_CLOCK_H
