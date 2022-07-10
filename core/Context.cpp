//
// Created by ilyabelow on 04/07/2022.
//

#include "Context.h"

Context::Context(Canvas canvas, MousePtr mouse) :
    canvas(canvas),
    mouse(std::move(mouse)) {}

void Context::act(float dt) {
    for (int i = 0; i < actGroup.size(); ++i) {
        if (actGroup[i]->isActive() && !actGroup[i]->isZombie()) {
            actGroup[i]->act(dt);
        }
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
            if (layer[i]->isActive() && !layer[i]->isZombie()) {
                layer[i]->draw();
            }
        }
    }
}

Canvas Context::getCanvas() {
    return canvas;
}

MousePtr Context::getMouse() {
    return mouse;
}

Group &Context::getGroup(const std::string& name) {
    return groups[name];
}

void Context::add(const EntityPtr &entity) {
    actGroup.push_back(entity);
    if (entity->renderLayer() >= 0) {
        renderGroups[entity->renderLayer()].push_back(entity);
    }
    reg(entity, entity->groupsNames());
}

void Context::reg(const EntityPtr &entity, const std::vector<std::string>& names) {
    for (auto &name: names) {
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
void Group::activate() {
    for (auto& entity: *this) {
        entity->activate();
    }
}
void Group::deactivate() {
    for (auto& entity: *this) {
        entity->deactivate();
    }
}
