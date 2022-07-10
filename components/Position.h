//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_POSITION_H
#define COMPUTERSPIEL_POSITION_H

#include "../math/Vector.h"

class Position {
public:
    explicit Position(Vector pos): pos(pos) {}

    [[nodiscard]] Vector getPos() const{
        return pos;
    }
    Vector pos;
};

#endif //COMPUTERSPIEL_POSITION_H
