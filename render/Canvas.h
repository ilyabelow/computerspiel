//
// Created by ilyabelow on 04/07/2022.
//

#ifndef COMPUTERSPIEL_CANVAS_H
#define COMPUTERSPIEL_CANVAS_H

#include <cstdint>
#include <vector>

#include "Color.h"
#include "../math/Point.h"
#include "../math/Vector.h"
#include "../math/Rect.h"
#include "Text.h"

class Canvas {
public:
    Canvas(uint32_t *buffer, int width, int height);

    void placePixel(Point p, Color c);
    void placePixel(int x, int y, Color c);

    void drawLine(Point p1, Point p2, Color c);

    void drawRect(Point p1, Point p2, Color c);
    void drawRect(Rect rect, Color c);
    void drawRect(Point center, int w, int h, Color c);

    void drawRotatedRectInside(Point center, int w, int h, float phi, Color c);
    void drawRotatedRectLine(Point center, int w, int h, float phi, Color c);

    void drawCircleInside(Point center, float r, Color c);
    void drawCircleLine(Point center, float r, Color c);
    void drawArc(Point center, float r, float phi1, float phi2, Color c);

    void drawText(Point start, const std::string &text, int s, Color c);
    void drawText(Point p, const Text& text);

    void clean();
    void clean(Color c);

    [[nodiscard]] Rect rect() const;

    const int width;
    const int height;
private:
    uint32_t *buffer;

};

#endif //COMPUTERSPIEL_CANVAS_H
