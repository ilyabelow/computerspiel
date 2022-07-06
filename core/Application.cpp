//
// Created by ilyabelow on 06/07/2022.
//

#include <iostream>
#include <cassert>
#include "Application.h"
#include "../entities/ui/Button.h"
#include "../entities/ui/Label.h"
#include "../entities/game/Player.h"
#include "../entities/game/Listener.h"

#include "../Engine.h"

Application::Application(const Canvas& canvas): canvas(canvas) {
    initMenu();
    current = menu;
}

void Application::draw() {
    canvas.clean();
    if (gamePaused) {
        game->draw();
    }
    current->draw();
}

void Application::act(float dt) {
    ContextPtr noDeleteWhileAct = current;
    current->act(dt);
}

void Application::initGame() {
    game = std::make_shared<Context>(canvas, Vector(0, 0), Vector(2000, 1000));
    game->add<Player>(Vector(300, 300));
    game->add<Listener>([this](){
        if (is_key_pressed(VK_ESCAPE)) {
            pauseGame();
        }
    });
}

void Application::initMenu() {
    int w = canvas.width;
    int h = canvas.height;
    menu = std::make_shared<Context>(canvas, Vector(0, 0), Vector(w, h));

    int w_center = w / 2;
    int button_width = 300;
    int button_height = 75;
    int logo_width = 700;
    int logo_height = 500;
    int vert_dist = (h - button_height*2 - logo_height) / 4;
    assert(vert_dist > 0);
    menu->add<Button>(Point(w_center-button_width/2,logo_height + vert_dist*2),
                      button_width,
                      button_height,
                      [this](){startGame();}
                      );
    menu->add<Button>(Point(w_center-button_width/2, logo_height + vert_dist*3 + button_height),
                      button_width,
                      button_height,
                      [](){schedule_quit_game();}
    );
    menu->add<Label>(Point(w_center-logo_width/2,  vert_dist),
                     logo_width,
                     logo_height
    );
    menu->add<Listener>([this](){
        if (is_key_pressed(VK_ESCAPE)) {
            schedule_quit_game();
            return;
        }
        if (is_key_pressed(VK_SPACE)) {
            startGame();
        }
    });
}

void Application::startGame() {
    menu.reset();
    initGame();
    initPause();
    current = game;
}

void Application::quitGame() {
    game.reset();
    pause.reset();
    initMenu();
    gamePaused = false;
    current = menu;
}

void Application::initPause() {
    int w = canvas.width;
    int h = canvas.height;
    pause = std::make_shared<Context>(canvas, Vector(0, 0), Vector(w, h));

    int w_center = w / 2;

    int label_width = 500;
    int label_height = 200;

    int title_width = 300;
    int title_height = 75;

    int button_width = 150;
    int button_height = 50;

    int hor_margins = (label_width - button_width*2) / 3;
    int ver_margins = (label_height - title_height - button_height) / 3;
    int above_padding = (h - label_height) / 2;

    pause->add<Button>(Point(w_center-button_width - hor_margins/2,title_height + above_padding + ver_margins*2),
                      button_width,
                      button_height,
                      [this](){unpauseGame();}
    );
    pause->add<Button>(Point(w_center + hor_margins/2,title_height + above_padding + ver_margins*2),
                      button_width,
                      button_height,
                      [this](){quitGame();}
    );
    pause->add<Label>(Point(0,  0),
                     w,
                     h,
                     Color("FFFFFF", 50)
    );
    pause->add<Label>(Point(w_center-label_width/2,  above_padding),
                     label_width,
                     label_height,
                     "8080FF"
    );
    pause->add<Label>(Point(w_center-title_width/2,  above_padding+ver_margins),
                     title_width,
                     title_height,
                     "80FF80"
    );
    pause->add<Listener>([this](){
        if (is_key_pressed(VK_ESCAPE)) {
            unpauseGame();
        }
    });
}

void Application::pauseGame() {
    current = pause;
    gamePaused = true;
}
void Application::unpauseGame() {
    current = game;
    gamePaused = false;
}
