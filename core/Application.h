//
// Created by ilyabelow on 06/07/2022.
//

#ifndef COMPUTERSPIEL_APPLICATION_H
#define COMPUTERSPIEL_APPLICATION_H

#include "../utils/Mouse.h"
#include "../render/Canvas.h"
#include "Context.h"

class Application {
public:
    explicit Application(const Canvas& screen);

    void draw();

    void act(float dt);

private:
    Canvas canvas;
    std::shared_ptr<Mouse> mouse;

    void initGame ();
    void initMenu ();
    void initPause ();

    void startGame();
    void quitGame();
    void pauseGame();
    void unpauseGame();

    ContextPtr game;
    ContextPtr menu;
    ContextPtr pause;
    ContextPtr current;

    bool gamePaused{};
};

#endif //COMPUTERSPIEL_APPLICATION_H
