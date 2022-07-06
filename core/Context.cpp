//
// Created by ilyabelow on 04/07/2022.
//

#include <iostream>
#include "Context.h"
#include "../entities/game/Player.h"

Context::Context(Canvas canvas, Vector r1, Vector r2) :
    canvas(canvas),
    upLeftCorner(r1),
    downRightCorner(r2) {}



void Context::act(float dt) {
    for (int i = 0; i < entities.size(); ++i) {
        cleanTrash(entities, i);
        if (i < entities.size()) {
            entities[i]->act(dt);
        }
    }
    for (auto &newEntity : newEntities) {
        entities.push_back(std::move(newEntity));
    }
    newEntities.clear();
}

void Context::draw() {
    for (int l = 0; l < LAYERS; l++) {
        auto& layer = layers[l];
        for (int i = 0; i < layer.size(); ++i) {
            cleanTrash(layer, i);
            if (i < layer.size()) {
                layer[i]->draw();
            }
        }
    }
}

Canvas &Context::getCanvas() {
    return canvas;
}

void Context::cleanTrash(std::vector<EntityPtr>& container, int i) {
    while (i < container.size() && container[i]->isTrash()) {
        container[i] = std::move(container[container.size() - 1]);
        container.pop_back();
    }
}

