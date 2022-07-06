#include <iostream>
#include "Engine.h"

#include "core/Application.h"
//
//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, VK_RETURN)
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  schedule_quit_game() - quit game after act()

//  Ideally I would not make Context global, but since Engine.cpp cannot be edited I have no other choice
Application *app;

// initialize game data in this function
void initialize() {
    app = new Application(Canvas(reinterpret_cast<uint32_t *>(buffer), SCREEN_WIDTH, SCREEN_HEIGHT));
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt) {
    app->act(dt);
}

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors (8 bits per R, G, B)
void draw() {
    app->draw();
}

// free game data in this function
void finalize() {
    delete app;
}

