//
// Created by ilyabelow on 07/07/22.
//

#include "Background.h"

#include <utility>

#include <utility>

#include "../../math/Math.h"

Background::Background(ContextWeakPtr game, std::shared_ptr<Player> player) :
    Entity(std::move(game)),
    player(std::move(player)){

    Rect screen = context()->getCanvas().rect();

    int shift_h = screen.p2.x;
    int shift_v = screen.p2.y;
    frontRect = Rect({screen.p1.x, screen.p1.y},
                     {screen.p2.x + shift_h / F_SHIFT, screen.p2.y + shift_v / F_SHIFT});
    backRect = Rect({screen.p1.x, screen.p1.y},
                    {screen.p2.x + shift_h / B_SHIFT, screen.p2.y + shift_v / B_SHIFT});
    for (int i = 0; i < 50; i++) {
        int x = randomInt(frontRect.p1.x, frontRect.p2.x);
        int y = randomInt(frontRect.p1.y, frontRect.p2.y);

        frontStars.emplace_back(Vector(x, y), Vector(-20, 0), 1, Color(255));
    }
    for (int i = 0; i < 100; i++) {
        int x = randomInt(backRect.p1.x, backRect.p2.x);
        int y = randomInt(backRect.p1.y, backRect.p2.y);

        backStars.emplace_back(Vector(x, y), Vector(-10, 0), 1, Color(128));
    }
}

void Background::draw() const {
    Canvas canvas = context()->getCanvas();
    for (auto &star: backStars) {
        canvas.drawCircleInside(star.pos - player->getPos() / B_SHIFT,
                                star.radius, star.color);
    }
    for (auto &star: frontStars) {
        canvas.drawCircleInside(star.pos - player->getPos() / F_SHIFT,
                                star.radius, star.color);
    }
}

void Background::act(float dt) {
    for (auto &star: backStars) {
        star.pos += star.vel * dt;
        if (star.pos.x + star.radius < 0) {
            star.pos.x = backRect.p2.x;
        }
    }
    for (auto &star: frontStars) {
        star.pos += star.vel * dt;
        if (star.pos.x + star.radius < 0) {
            star.pos.x = frontRect.p2.x;
        }
    }
}
int Background::renderLayer() const {
    return 0;
}

Star::Star(Vector pos, Vector vel, int radius, Color color) : pos(pos), vel(vel), radius(radius), color(color) {

}
