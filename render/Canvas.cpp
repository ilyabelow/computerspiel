//
// Created by ilyabelow on 04/07/2022.
//

#include "Canvas.h"
#include "../math/Math.h"

Canvas::Canvas(uint32_t *buffer, int width, int height) : buffer(buffer),
                                                          width(width),
                                                          height(height) {}

void Canvas::placePixel(Point p, Color c) {
    placePixel(p.x, p.y, c);
}

void Canvas::placePixel(int x, int y, Color c) {
    if (x < 0 || y < 0 || x >= width || y >= height) {
        return;
    }
    *(buffer + y * width + x) = c.getBytes();
}

void Canvas::clean() {
    memset(buffer, 0, height * width * sizeof(uint32_t));
}

void Canvas::clean(Color c) {
    for (int i = 0; i < width*height; ++i) {
        *(buffer + i) = c.getBytes();
    }
}

void Canvas::drawRect(Point p1, Point p2, Color c) {
    for (int x = p1.x; x < p2.x; ++x) {
        for (int y = p1.y; y < p2.y; ++y) {
            placePixel(x, y, c);
        }
    }
}

void Canvas::drawRect(Point center, int w, int h, Color c) {
    int left = center.x-w/2;
    int right = center.x+w/2;
    int up =  center.y-h/2;
    int down = center.y+h/2;
    for (int x = left; x < right; ++x) {
        for (int y = up; y < down; ++y) {
            placePixel(x, y, c);
        }
    }
}
void Canvas::drawCircle(Point center, int r, Color c) {
    int left = center.x-r;
    int right = center.x+r;
    int up =  center.y-r;
    int down = center.y+r;
    for (int x = left; x < right; ++x) {
        for (int y = up; y < down; ++y) {
            int d = sqr(center.x-x) + sqr(center.y-y);
            if (d <= sqr(r)) {
                placePixel(x, y, c);
            }
        }
    }
}

