//
// Created by ilyabelow on 09/07/22.
//

#ifndef COMPUTERSPIEL_TEXT_H
#define COMPUTERSPIEL_TEXT_H

#include <string>
#include "Color.h"

struct Text {
    std::string text;
    int size;
    Color color;

    [[nodiscard]] int width() const {
        return size * static_cast<int>(text.size());
    }
};

#endif //COMPUTERSPIEL_TEXT_H
