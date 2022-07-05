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
    Game(Canvas canvas, Vector r1, Vector r2);

    void init();

    void act(float dt);
    void draw();

    template <typename T, typename... Args>
    void add(Args&&... args) {
        EntityPtr entity = std::make_shared<T>(weak_from_this(), std::forward<Args>(args)...);
        newEntities.push_back(entity);
    }

    Canvas& getCanvas();

    const Vector upLeftCorner;
    const Vector downRightCorner;

private:

    Canvas canvas;
    std::vector<std::vector<EntityWeakPtr>> layers;

    std::vector<EntityPtr> entities{};
    std::vector<EntityPtr> newEntities{};
};


#endif //COMPUTERSPIEL_GAME_H
