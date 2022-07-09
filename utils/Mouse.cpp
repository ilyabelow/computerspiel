//
// Created by ilyabelow on 07/07/22.
//

#include "Mouse.h"

#include "../Engine.h"

Point Mouse::cursor() const {
    return {get_cursor_x(), get_cursor_y()};
}

bool Mouse::isPressed(int button) const {
    return is_mouse_button_pressed(button);
}

bool Mouse::isReleased(int button) const {
    return prev[button] && !is_mouse_button_pressed(button);
}

bool Mouse::isClicked(int button) const {
    return !prev[button] && is_mouse_button_pressed(button);
}

void Mouse::update() {
    for (int i = 0; i < 3; ++i) {
        prev[i] = is_mouse_button_pressed(i);
    }
}