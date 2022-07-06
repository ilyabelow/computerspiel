//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_COLOR_H
#define COMPUTERSPIEL_COLOR_H

#include <cstdint>

class Color {
public:
    Color() = default;

    Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
        color[0] = blue;
        color[1] = green;
        color[2] = red;
        color[3] = alpha;
    }

    Color(uint8_t red, uint8_t green, uint8_t blue) : Color(red, green, blue, 255) {}

    Color(const uint32_t *c) {
        *reinterpret_cast<uint32_t* >(color) = *c;
    }

    Color(const char *code, int alpha) noexcept: Color(fromHex(code),
                                                       fromHex(code + 2),
                                                       fromHex(code + 4), alpha) {}

    Color(const char *code) noexcept: Color(code, 255) {}

    [[nodiscard]] uint8_t red() const {
        return color[2];
    }

    [[nodiscard]] uint8_t green() const {
        return color[1];
    }

    [[nodiscard]] uint8_t blue() const {
        return color[0];
    }

    [[nodiscard]] uint8_t alpha() const {
        return color[3];
    }

    Color operator+(const Color& other) const {
        if (other.alpha() == 255) {
            return other;
        }
        uint8_t newRed = (red() * (255-other.alpha()) * alpha() + other.red() * other.alpha() * 255) / 255 / 255;
        uint8_t newGreen = (green() * (255-other.alpha()) * alpha()  + other.green() * other.alpha()*255) / 255 / 255;
        uint8_t newBlue = (blue() * (255-other.alpha()) * alpha() + other.blue() * other.alpha()*255) / 255 / 255;
        uint8_t newAlpha = (other.alpha()*255 + (255-other.alpha())*alpha()) / 255;
        return {newRed, newGreen, newBlue, newAlpha};
    }

    [[nodiscard]] uint32_t getBytes() const {
        return *reinterpret_cast<const uint32_t *>(color);
    }

private:
    uint8_t color[4];

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
