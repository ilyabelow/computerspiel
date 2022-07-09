//
// Created by ilyabelow on 07/07/22.
//

#ifndef COMPUTERSPIEL_MOUSE_H
#define COMPUTERSPIEL_MOUSE_H

#include <array>
#include <memory>
#include "../math/Point.h"

class Mouse {
public:
    Mouse() = default;

    [[nodiscard]] bool isPressed(int button) const;
    [[nodiscard]] bool isClicked(int button) const;
    [[nodiscard]] bool isReleased(int button) const;
    [[nodiscard]] Point cursor() const;

    void update();
private:
    std::array<bool, 3> prev;
};

typedef std::shared_ptr<Mouse> MousePtr;

#endif //COMPUTERSPIEL_MOUSE_H
