//
// Created by ilyabelow on 06/07/2022.
//

#include <iostream>
#include <cassert>
#include <utility>
#include "Application.h"
#include "../entities/ui/Button.h"
#include "../entities/ui/Label.h"
#include "../entities/game/Player.h"
#include "../entities/control/Listener.h"

#include "../Engine.h"
#include "../entities/game/Background.h"
#include "../entities/game/enemies/Enemy.h"
#include "../entities/control/Spawner.h"
#include "../entities/ui/Title.h"

Application::Application(const Canvas &screen) :
    canvas(screen),
    mouse(std::make_shared<Mouse>()) {
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
    mouse->update();
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

void Application::pauseGame() {
    current = pause;
    gamePaused = true;
}
void Application::unpauseGame() {
    current = game;
    gamePaused = false;
}

void Application::initGame() {
    game = std::make_shared<Context>(canvas, mouse);

    auto player = game->add<Player>(Vector(canvas.width / 2, 500));

    game->add<Listener>([this]() {
        if (is_key_pressed(VK_ESCAPE)) {
            pauseGame();
        }
    });
    game->add<Spawner>();

    game->add<Background>(player);
}

void Application::initMenu() {
    int w = canvas.width;
    int h = canvas.height;
    menu = std::make_shared<Context>(canvas, mouse);

    int w_center = w / 2;
    int button_width = 320;
    int text_size = button_width / 8;
    int text_margin = 10;
    int button_height = text_size + 2 * text_margin;

    int top_margin = 50;
    int between_buttons = 30;
    int title_width = Title::WIDTH();
    int title_height = Title::HEIGHT();
    int buttons_margin = (h - top_margin - title_height - button_height * 2 - between_buttons) / 2;

    menu->add<Title>(Point(w_center - title_width / 2, top_margin));

    menu->add<Button>(Rect({w_center - button_width / 2,
                            h - button_height * 2 - buttons_margin - between_buttons},
                           button_width,
                           button_height
                      ),
                      Point(w_center - button_width / 2,
                            top_margin +
                                title_height +
                                buttons_margin +
                                text_margin
                      ),
                      Text("- PLAY -", text_size, WHITE),
                      [this]() { startGame(); }
    );
    menu->add<Button>(Rect({w_center - button_width / 2,
                            h - button_height - buttons_margin},
                           button_width,
                           button_height
                      ),
                      Point(w_center - button_width / 2,
                            top_margin +
                                title_height +
                                buttons_margin +
                                button_height +
                                between_buttons +
                                text_margin
                      ),
                      Text("- QUIT -", text_size, WHITE),
                      []() { schedule_quit_game(); }
    );
}

void Application::initPause() {
    int w = canvas.width;
    int h = canvas.height;
    pause = std::make_shared<Context>(canvas, mouse);

    int w_center = w / 2;

    int plate_width = 500;
    int plate_height = 200;


    int text_size = 25;
    int button_1_width = 8*text_size;
    int button_2_width = 9*text_size;

    int prompt_height = 30;

    int button_width_total = button_1_width+button_2_width;

    int text_margin = 10;
    int button_height = text_size + 2 * text_margin;


    int hor_margins = (plate_width - button_width_total) / 3;
    int ver_margins = (plate_height - prompt_height - button_height) / 3;
    int above_padding = (h - plate_height) / 2;
    // Main plate
    pause->add<Plate>(Rect({w_center - plate_width / 2, above_padding},
                           plate_width,
                           plate_height),
                      "8080FF");
    // Continue button
    pause->add<Button>(
        Rect({w_center - plate_width/2+hor_margins, prompt_height + above_padding + ver_margins * 2},
             button_1_width,
             button_height),
        Point(w_center - plate_width/2+hor_margins, prompt_height + above_padding + ver_margins * 2 + text_margin),
        Text("CONTINUE", text_size, WHITE),
        [this]() { unpauseGame(); }
    );
    // Quit button
    pause->add<Button>(

        Rect({w_center + plate_width/2-hor_margins-button_2_width, prompt_height + above_padding + ver_margins * 2},
             button_2_width,
             button_height),
        Point(w_center + plate_width/2-hor_margins-button_2_width, prompt_height + above_padding + ver_margins * 2+ text_margin),
        Text("STOP GAME", text_size, WHITE),
        [this]() { quitGame(); }
    );
    // Prompt
    pause->add<Label> (Point(w_center-13*prompt_height/2, above_padding+ver_margins),
                       Text("ARE YOU SURE?", prompt_height, WHITE));

}
