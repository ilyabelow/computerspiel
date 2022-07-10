//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_SCORE_H
#define COMPUTERSPIEL_SCORE_H

#include "NotRendered.h"
#include "../ui/Label.h"

class Score : public NotRendered {
public:
    Score(ContextWeakPtr game) :
        NotRendered(std::move(game)),
        scoreLabel(context()->add<Label>(Point(10, 50), Text("SCORE: 0", 30, WHITE))) {}

    void act(float dt) override {

    }
    [[nodiscard]] std::vector<std::string> groupsNames() const override {
        return {"score"};
    }

    void add(int delta) {
        score += delta;
        scoreLabel->changeText("SCORE: " + std::to_string(score));
    }

    ~Score() override = default;
private:
    std::shared_ptr<Label> scoreLabel;
    int score = 0;
};

#endif //COMPUTERSPIEL_SCORE_H
