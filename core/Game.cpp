//
// Created by ilyabelow on 04/07/2022.
//

#include "Game.h"
#include "../Engine.h"
#include "../render/Color.h"
#include "../entities/Player.h"

Game::Game(Canvas canvas): canvas(canvas) {
}

void Game::init() {
    entities.push_back(std::make_shared<Player>(weak_from_this(), Vector(100,100)));
}

void Game::act(float dt) {
    if (is_key_pressed(VK_ESCAPE)) {
        schedule_quit_game();
    }
    for (auto& entity: entities) {
        entity->act(dt);
    }
}

void Game::draw() {
    canvas.clean();
    for (auto& entity: entities) {
        entity->draw();
    }
}

Canvas &Game::getCanvas() {
    return canvas;
}

