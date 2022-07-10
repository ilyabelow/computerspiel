//
// Created by ilyabelow on 10/07/22.
//

#ifndef COMPUTERSPIEL_POSITION_H
#define COMPUTERSPIEL_POSITION_H

#include "../math/Vector.h"

class Position {
public:
    [[nodiscard]] Vector getPos() const{
        return pos;
    }
protected:
    Position(Vector pos): pos(pos) {}


    Vector pos;
};

#endif //COMPUTERSPIEL_POSITION_H
