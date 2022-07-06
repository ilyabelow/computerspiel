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

class Canvas {
public:
    Canvas(uint32_t *buffer, int width, int height);

    void placePixel(Point p, Color c);

    void placePixel(int x, int y, Color c);

    void drawRect(Point p1, Point p2, Color c);

    void drawRect(Point center, int w, int h, Color c);

    void drawCircle(Point center, int r, Color c);

    void drawLine(Point p1, Point p2, Color c);

    void clean();

    void clean(Color c);

    const int width;
    const int height;
private:
    uint32_t *buffer;

};

#endif //COMPUTERSPIEL_CANVAS_H
