//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_CONTEXT_H
#define COMPUTERSPIEL_CONTEXT_H

#include "../render/Canvas.h"

#include <vector>
#include <memory>
#include <array>
#include <unordered_map>

class Context;

typedef std::weak_ptr<Context> ContextWeakPtr;
typedef std::shared_ptr<Context> ContextPtr;

#include "../entities/Entity.h"
#include "../utils/Mouse.h"

class Group : public std::vector<EntityPtr> {
public:
    void takeOutTrash();
    void activate();
    void deactivate();
};

class Context : public std::enable_shared_from_this<Context> {
public:
    Context(Canvas canvas, MousePtr mouse);

    void act(float dt);
    void draw();

    template<typename T, typename... Args>
    std::shared_ptr<T> add(Args &&... args) {
        std::shared_ptr<T> entity = create<T>(std::forward<Args>(args)...);
        add(entity);
        return entity;
    }

    template<typename T, typename... Args>
    std::shared_ptr<T> create(Args &&... args) {
        auto entity = std::make_shared<T>(weak_from_this(), std::forward<Args>(args)...);
        return entity;
    }

    void add(const EntityPtr &entity);
    void reg(const EntityPtr &entity, const std::vector<std::string>& names);

    Canvas getCanvas();
    MousePtr getMouse();
    Group &getGroup(const std::string& name);

private:
    Canvas canvas;
    MousePtr mouse;

    Group actGroup{};
    static const size_t LAYERS = 8;
    std::array<Group, LAYERS> renderGroups;
    std::unordered_map<std::string, Group> groups;

};

#endif //COMPUTERSPIEL_CONTEXT_H
