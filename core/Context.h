//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_CONTEXT_H
#define COMPUTERSPIEL_CONTEXT_H

#include "../render/Canvas.h"
#include "../math/Vector.h"

#include <vector>
#include <memory>
#include <array>

class Context;

typedef std::weak_ptr<Context> ContextWeakPtr;
typedef std::shared_ptr<Context> ContextPtr;

#include "../entities/Entity.h"
#include "../math/Rect.h"
#include "../utils/Mouse.h"

class Context: public std::enable_shared_from_this<Context> {
public:
    Context(Canvas canvas, MousePtr mouse);

    void act(float dt);
    void draw();

    template <typename T, typename... Args>
    std::shared_ptr<T> add(Args&&... args) {
        std::shared_ptr<T> entity = std::make_shared<T>(weak_from_this(), std::forward<Args>(args)...);
        newEntities.push_back(entity);
        if (entity->renderLayer() >= 0) {
            layers[entity->renderLayer()].push_back(entity);
        }
        return entity;
    }

    Canvas getCanvas();
    MousePtr getMouse();
private:
    void cleanTrash(std::vector<EntityPtr>& container, int i);

    Canvas canvas;
    MousePtr mouse;

    static const size_t LAYERS = 8;
    std::array<std::vector<EntityPtr>, LAYERS> layers;

    std::vector<EntityPtr> entities{};
    std::vector<EntityPtr> newEntities{};


};


#endif //COMPUTERSPIEL_CONTEXT_H
