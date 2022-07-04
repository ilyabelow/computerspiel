//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_GAME_H
#define COMPUTERSPIEL_GAME_H

#include "../render/Canvas.h"
#include "../math/Vector.h"

#include <vector>
#include <memory>

class Game;

typedef std::weak_ptr<Game> GamePtr;

#include "../entities/Entity.h"

class Game: public std::enable_shared_from_this<Game> {
public:
    Game(Canvas canvas);

    void init();

    void act(float dt);

    void draw();

    Canvas& getCanvas();
private:
    Canvas canvas;

    std::vector<EntityPtr> entities{};
};


#endif //COMPUTERSPIEL_GAME_H
