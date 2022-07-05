//
// Created by ilyabelow on 04/07/2022.
//

#include "Game.h"
#include "../Engine.h"
#include "../entities/Player.h"

Game::Game(Canvas canvas, Vector r1, Vector r2) :
    canvas(canvas),
    upLeftCorner(r1),
    downRightCorner(r2) {}

void Game::init() {
    add<Player>(Vector(100, 100));
}

void Game::act(float dt) {
    if (is_key_pressed(VK_ESCAPE)) {
        schedule_quit_game();
    }
    for (auto &entity: entities) {
        entity->act(dt);
    }

    for (int i = 0; i < entities.size(); ++i) {
        while (i < entities.size() && entities[i]->isTrash()) {
            entities[i] = std::move(entities[entities.size() - 1]);
            entities.pop_back();
        }
    }

    for (auto &newEntity : newEntities) {
        entities.push_back(std::move(newEntity));
    }
    newEntities.clear();
}

void Game::draw() {
    canvas.clean();
    for (auto &entity: entities) {
        entity->draw();
    }
}

Canvas &Game::getCanvas() {
    return canvas;
}

