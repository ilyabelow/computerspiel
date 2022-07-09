//
// Created by ilyabelow on 04/07/2022.
//

#include "Context.h"

#include <utility>

Context::Context(Canvas canvas, MousePtr mouse) :
    canvas(canvas),
    mouse(std::move(mouse)) {}

void Context::act(float dt) {
    for (int i = 0; i < actGroup.size(); ++i) {
        actGroup[i]->act(dt);
    }
    actGroup.takeOutTrash();
    for (auto &layer: renderGroups) {
        layer.takeOutTrash();
    }
    for (auto &group: groups) {
        group.second.takeOutTrash();
    }
}

void Context::draw() {
    for (int l = 0; l < LAYERS; l++) {
        auto &layer = renderGroups[l];
        for (int i = 0; i < layer.size(); ++i) {
            layer[i]->draw();
        }
    }
}

Canvas Context::getCanvas() {
    return canvas;
}

MousePtr Context::getMouse() {
    return mouse;
}

Group &Context::getGroup(const std::string &name) {
    return groups[name];
}

void Context::add(const EntityPtr &entity) {
    actGroup.push_back(entity);
    if (entity->renderLayer() >= 0) {
        renderGroups[entity->renderLayer()].push_back(entity);
    }
    for (auto &name: entity->groupsNames()) {
        if (!groups.contains(name)) {
            groups[name] = {};
        }
        groups[name].push_back(entity);
    }
}

void Group::takeOutTrash() {
    int i = 0;
    while (i < size()) {
        while (i < size() && (*this)[i]->isZombie()) {
            (*this)[i] = std::move((*this)[size() - 1]);
            pop_back();
        }
        i++;
    }
}
