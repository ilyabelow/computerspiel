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
    uint32_t *pixel = buffer + y * width + x;
    Color currentColor(pixel);
    *(pixel) = (currentColor + c).getBytes();
}

void Canvas::clean() {
    clean("000000");
}

void Canvas::clean(Color c) {
    for (int i = 0; i < width * height; ++i) {
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
    int left = center.x - w / 2;
    int right = center.x + w / 2;
    int up = center.y - h / 2;
    int down = center.y + h / 2;
    for (int x = left; x < right; ++x) {
        for (int y = up; y < down; ++y) {
            placePixel(x, y, c);
        }
    }
}
void Canvas::drawCircleInside(Point center, float r, Color c) {
    for (int y = -r; y < r; ++y) {
        int len = std::sqrt(sqr(r) - sqr(y));
        for (int x = -len; x < len; ++x) {
            placePixel(center.x + x, center.y + y, c);
        }
    }
}

void Canvas::drawRect(Rect rect, Color c) {
    drawRect(rect.p1, rect.p2, c);
}

Rect Canvas::rect() const {
    return Rect({0, 0}, {width, height});
}

void Canvas::drawLine(Point p1, Point p2, Color c) {
    bool steep = std::abs(p2.y - p1.y) > std::abs(p2.x - p1.x);
    if (steep) {
        p1 = {p1.y, p1.x};
        p2 = {p2.y, p2.x};
    }
    if (p1.x > p2.x) {
        std::swap(p1, p2);
    }
    float slope = (p2.y - p1.y + 0.0) / (p2.x - p1.x);
    float y = p1.y;

    for (int x = p1.x; x <= p2.x; x++) {
        int whole = static_cast<int>(y);
        if (y < 0) {
            whole -= 1;
        }
        int remainder255 = static_cast<int>((y - static_cast<float>(whole)) * 255);
        if (steep) {
            placePixel(whole, x, c.withOpacity((255 - remainder255) * c.alpha() / 255));
            placePixel(whole + 1, x, c.withOpacity(remainder255 * c.alpha() / 255));
        } else {
            placePixel(x, whole, c.withOpacity((255 - remainder255) * c.alpha() / 255));
            placePixel(x, whole + 1, c.withOpacity(remainder255 * c.alpha() / 255));
        }
        y += slope;
    }
}

void Canvas::drawCircleLine(Point center, float r, Color c) {
    int x1 = center.x - r * M_SQRT1_2f;
    int x2 = center.x + r * M_SQRT1_2f;
    int y1 = center.y - r * M_SQRT1_2f;
    int y2 = center.y + r * M_SQRT1_2f;
    for (int x = x1; x <= x2; x++) {
        float y = center.y + std::sqrt(sqr(r) - sqr(x - center.x));
        int whole = static_cast<int>(y);
        int remainder255 = static_cast<int>((y - static_cast<float>(whole)) * 255);

        placePixel(x, whole, c.withOpacity((255 - remainder255) * c.alpha() / 255));
        placePixel(x, whole + 1, c.withOpacity(remainder255 * c.alpha() / 255));
    }
    for (int x = x1; x <= x2; x++) {
        float y = center.y - std::sqrt(sqr(r) - sqr(x - center.x));
        int whole = static_cast<int>(y);
        int remainder255 = static_cast<int>((y - static_cast<float>(whole)) * 255);

        placePixel(x, whole, c.withOpacity((255 - remainder255) * c.alpha() / 255));
        placePixel(x, whole + 1, c.withOpacity(remainder255 * c.alpha() / 255));
    }
    for (int y = y1; y <= y2; y++) {
        float x = center.x + std::sqrt(sqr(r) - sqr(y - center.y));
        int whole = static_cast<int>(x);
        int remainder255 = static_cast<int>((x - static_cast<float>(whole)) * 255);

        placePixel(whole, y, c.withOpacity((255 - remainder255) * c.alpha() / 255));
        placePixel(whole + 1, y, c.withOpacity(remainder255 * c.alpha() / 255));
    }
    for (int y = y1; y <= y2; y++) {
        float x = center.x - std::sqrt(sqr(r) - sqr(y - center.y));
        int whole = static_cast<int>(x);
        int remainder255 = static_cast<int>((x - static_cast<float>(whole)) * 255);

        placePixel(whole, y, c.withOpacity((255 - remainder255) * c.alpha() / 255));
        placePixel(whole + 1, y, c.withOpacity(remainder255 * c.alpha() / 255));
    }
}

void Canvas::drawArc(Point center, float r, float phi1, float phi2, Color c) {
    Vector centerV = center;
    int x1 = static_cast<int>(centerV.x - r * M_SQRT1_2f);
    int x2 = static_cast<int>(centerV.x + r * M_SQRT1_2f);
    int y1 = static_cast<int>(centerV.y - r * M_SQRT1_2f);
    int y2 = static_cast<int>(centerV.y + r * M_SQRT1_2f);
    for (int y = center.y; y <= y2; y++) {
        float x = centerV.x + std::sqrt(sqr(r) - sqr(y - center.y));
        float phi = atan2bound(y - centerV.y, x - centerV.x);
        if (!(phi > phi1 && phi < phi2 || phi + M_TAUf > phi1 && phi + M_TAUf < phi2)) {
            continue;
        }
        int whole = static_cast<int>(x);
        int remainder255 = static_cast<int>((x - static_cast<float>(whole)) * 255);

        placePixel(whole, y, c.withOpacity((255 - remainder255) * c.alpha() / 255));
        placePixel(whole + 1, y, c.withOpacity(remainder255 * c.alpha() / 255));
    }

    for (int x = x1; x <= x2; x++) {
        float y = centerV.y - std::sqrt(sqr(r) - sqr(x - center.x));
        float phi = atan2bound(y - centerV.y, x - centerV.x);
        if (!(phi > phi1 && phi < phi2 || phi + M_TAUf > phi1 && phi + M_TAUf < phi2)) {
            continue;
        }
        int whole = static_cast<int>(y);
        int remainder255 = static_cast<int>((y - static_cast<float>(whole)) * 255);

        placePixel(x, whole, c.withOpacity((255 - remainder255) * c.alpha() / 255));
        placePixel(x, whole + 1, c.withOpacity(remainder255 * c.alpha() / 255));
    }
    for (int y = y1; y <= y2; y++) {
        float x = centerV.x - std::sqrt(sqr(r) - sqr(y - center.y));
        float phi = atan2bound(y - centerV.y, x - centerV.x);
        if (!(phi > phi1 && phi < phi2 || phi + M_TAUf > phi1 && phi + M_TAUf < phi2)) {
            continue;
        }
        int whole = static_cast<int>(x);
        int remainder255 = static_cast<int>((x - static_cast<float>(whole)) * 255);

        placePixel(whole, y, c.withOpacity((255 - remainder255) * c.alpha() / 255));
        placePixel(whole + 1, y, c.withOpacity(remainder255 * c.alpha() / 255));
    }
    for (int x = x1; x <= x2; x++) {
        float y = centerV.y + std::sqrt(sqr(r) - sqr(x - centerV.x));
        float phi = atan2bound(y - centerV.y, x - centerV.x);
        if (!(phi > phi1 && phi < phi2 || phi + M_TAUf > phi1 && phi + M_TAUf < phi2)) {
            continue;
        }
        int whole = static_cast<int>(y);
        int remainder255 = static_cast<int>((y - static_cast<float>(whole)) * 255);

        placePixel(x, whole, c.withOpacity((255 - remainder255) * c.alpha() / 255));
        placePixel(x, whole + 1, c.withOpacity(remainder255 * c.alpha() / 255));
    }

    for (int y = y1; y < center.y; y++) {
        float x = centerV.x + std::sqrt(sqr(r) - sqr(y - center.y));
        float phi = atan2bound(y - centerV.y, x - centerV.x);
        if (!(phi > phi1 && phi < phi2 || phi + M_TAUf > phi1 && phi + M_TAUf < phi2)) {
            continue;
        }
        int whole = static_cast<int>(x);
        int remainder255 = static_cast<int>((x - static_cast<float>(whole)) * 255);

        placePixel(whole, y, c.withOpacity((255 - remainder255) * c.alpha() / 255));
        placePixel(whole + 1, y, c.withOpacity(remainder255 * c.alpha() / 255));
    }
}

void Canvas::drawRotatedRectLine(Point center, int w, int h, float phi, Color c) {
    Vector centerV = center;
    Vector ul = Vector(-w / 2, -h / 2).rotate(phi);
    Vector dl = Vector(-w / 2, h / 2).rotate(phi);
    Vector ur = Vector(w / 2, -h / 2).rotate(phi);
    Vector dr = Vector(w / 2, h / 2).rotate(phi);
    drawLine(centerV + ul, centerV + dl, c);
    drawLine(centerV + dl, centerV + dr, c);
    drawLine(centerV + dr, centerV + ur, c);
    drawLine(centerV + ur, centerV + ul, c);
}

void Canvas::drawRotatedRectInside(Point center, int w, int h, float phi, Color c) {

}
