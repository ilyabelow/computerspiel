//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_COLOR_H
#define COMPUTERSPIEL_COLOR_H

#include <cstdint>

class Color {
public:
    Color() = default;

    Color(uint8_t red, uint8_t green, uint8_t blue) {
        color[0] = blue;
        color[1] = green;
        color[2] = red;
        color[3] = 255;
    }

    Color(const char *code) noexcept: Color(fromHex(code),
                                            fromHex(code + 2),
                                            fromHex(code + 4)) {}

    [[nodiscard]] uint8_t getRed() const {
        return color[0];
    }

    [[nodiscard]] uint8_t getGreen() const {
        return color[1];
    }

    [[nodiscard]] uint8_t getBlue() const {
        return color[2];
    }

    [[nodiscard]] uint32_t getBytes() const {
        return *reinterpret_cast<const uint32_t*>(color);
    }

private:
    uint8_t color[4]{};

    uint8_t fromHex(const char *c) {
        return resolveHexOneDigit(c[0]) * 16 + resolveHexOneDigit(c[1]);
    }

    uint8_t resolveHexOneDigit(char c) {
        if ('0' <= c && c <= '9') {
            return c - '0';
        }
        if ('A' <= c && c <= 'F') {
            return c - 'A' + 10;
        }
        if ('a' <= c && c <= 'f') {
            return c - 'a' + 10;
        }
        return 0; // should never run
    }

};

const Color WHITE = "FFFFFF";
const Color BLACK = "000000";

const Color RED = "FF0000";
const Color GREEN = "00FF00";
const Color BLUE = "0000FF";

const Color YELLOW = "FFFF00";
const Color PURPLE = "FF00FF";

#endif //COMPUTERSPIEL_COLOR_H
