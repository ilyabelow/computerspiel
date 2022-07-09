//
// Created by ilyabelow on 09/07/22.
//

#include "Canvas.h"
#include "../math/Math.h"

void Canvas::drawText(Point p, const Text &text) {
    drawText(p, text.text, text.size, text.color);
}

void Canvas::drawText(Point start, const std::string &text, int s, Color c) {
    Point pos = start;
    int betweenLetters = 0;
    for (char letter: text) {
        switch (letter) {
            case 'A':
                drawLine(pos + Point(s / 4, s), pos + Point(s / 2, 0), c);
                drawLine(pos + Point(3 * s / 4, s), pos + Point(s / 2, 0), c);
                drawLine(pos + Point(3 * s / 8, s / 2), pos + Point(5 * s / 8, s / 2), c);
                break;
            case 'B':
                drawLine(pos + Point(3 * s / 8, 0), pos + Point(3 * s / 8, s), c);
                drawArc(pos + Point(3 * s / 8, s / 4), s / 4, 3 * M_PI_2f, 5 * M_PI_2f, c);
                drawArc(pos + Point(3 * s / 8, 3 * s / 4), s / 4, 3 * M_PI_2f, 5 * M_PI_2f, c);
                break;
            case 'C':
                drawArc(pos + Point(s / 2, s / 4), s / 4, M_PIf, M_TAUf, c);
                drawArc(pos + Point(s / 2, 3*s / 4), s / 4, 0, M_PIf, c);
                drawLine(pos + Point(s / 4, s/4), pos + Point(s / 4, 3*s/4), c);

                break;
            case 'D':
                drawArc(pos + Point(s / 4, s / 2), s / 2, 3 * M_PI_2f, 5 * M_PI_2f, c);
                drawLine(pos + Point(s / 4, 0), pos + Point(s / 4, s), c);
                break;
            case 'E':
                drawLine(pos + Point(s / 4, 0), pos + Point(s / 4, s), c);
                drawLine(pos + Point(s / 4, 0), pos + Point(3 * s / 4, 0), c);
                drawLine(pos + Point(s / 4, s / 2), pos + Point(3 * s / 4, s / 2), c);
                drawLine(pos + Point(s / 4, s), pos + Point(3 * s / 4, s), c);
                break;
            case 'F':drawLine(pos + Point(s / 4, 0), pos + Point(s / 4, s), c);
                drawLine(pos + Point(s / 4, 0), pos + Point(3 * s / 4, 0), c);
                drawLine(pos + Point(s / 4, s / 2), pos + Point(3 * s / 4, s / 2), c);
                break;
            case 'G':
                drawArc(pos + Point(s / 2, s / 4), s / 4, M_PIf, M_TAUf, c);
                drawArc(pos + Point(s / 2, 3*s / 4), s / 4, 0, M_PIf, c);
                drawLine(pos + Point(s / 4, s/4), pos + Point(s / 4, 3*s/4), c);
                drawLine(pos + Point(3*s / 4, s/2), pos + Point(3*s / 4, 3*s/4), c);
                drawLine(pos + Point(3*s / 4, s/2), pos + Point(s / 2, s/2), c);
                break;
            case 'H':
                drawLine(pos + Point(s / 4, 0), pos + Point(s / 4, s), c);
                drawLine(pos + Point(3 * s / 4, 0), pos + Point(3 * s / 4, s), c);
                drawLine(pos + Point(s / 4, s / 2), pos + Point(3 * s / 4, s / 2), c);
                break;
            case 'I':
                drawLine(pos + Point(s / 2, 0), pos + Point(s / 2, s), c);
                drawLine(pos + Point(3 * s / 8, 0), pos + Point(5 * s / 8, 0), c);
                drawLine(pos + Point(3 * s / 8, s), pos + Point(5 * s / 8, s), c);
                break;
            case 'J':
                drawLine(pos + Point(s / 2, 0), pos + Point(s / 2, 7 * s / 8), c);
                drawLine(pos + Point(3 * s / 8, 0), pos + Point(5 * s / 8, 0), c);
                drawArc(pos + Point(3 * s / 8, 7 * s / 8), s / 8, 0, M_PIf, c);
                break;
            case 'K':
                drawLine(pos + Point(s / 4, 0), pos + Point(s / 4, s), c);
                drawLine(pos + Point(s / 4, s / 2), pos + Point(3 * s / 4, 0), c);
                drawLine(pos + Point(s / 4, s / 2), pos + Point(3 * s / 4, s), c);
                break;
            case 'L':
                drawLine(pos + Point(s / 4, 0), pos + Point(s / 4, s), c);
                drawLine(pos + Point(s / 4, s), pos + Point(3 * s / 4, s), c);
                break;
            case 'M':
                drawLine(pos + Point(s / 4, 0), pos + Point(s / 4, s), c);
                drawLine(pos + Point(3 * s / 4, 0), pos + Point(3 * s / 4, s), c);
                drawLine(pos + Point(s / 4, 0), pos + Point(s / 2, s / 4), c);
                drawLine(pos + Point(3 * s / 4, 0), pos + Point(s / 2, s / 4), c);
                break;
            case 'N':
                drawLine(pos + Point(s / 4, 0), pos + Point(s / 4, s), c);
                drawLine(pos + Point(3 * s / 4, 0), pos + Point(3 * s / 4, s), c);
                drawLine(pos + Point(s / 4, 0), pos + Point(3 * s / 4, s), c);
                break;
            case 'O':
                drawArc(pos + Point(s / 2, s / 4), s / 4, M_PIf, M_TAUf, c);
                drawArc(pos + Point(s / 2, 3*s / 4), s / 4, 0, M_PIf, c);
                drawLine(pos + Point(s / 4, s/4), pos + Point(s / 4, 3*s/4), c);
                drawLine(pos + Point(3*s / 4, s/4), pos + Point(3*s / 4, 3*s/4), c);
                break;
            case 'P':
                drawLine(pos + Point(3 * s / 8, 0), pos + Point(3 * s / 8, s), c);
                drawArc(pos + Point(3 * s / 8, s / 4), s / 4, 3 * M_PI_2f, 5 * M_PI_2f, c);
                break;
            case 'Q':
                drawArc(pos + Point(s / 2, s / 4), s / 4, M_PIf, M_TAUf, c);
                drawArc(pos + Point(s / 2, 3*s / 4), s / 4, 0, M_PIf, c);
                drawLine(pos + Point(s / 4, s/4), pos + Point(s / 4, 3*s/4), c);
                drawLine(pos + Point(3*s / 4, s/4), pos + Point(3*s / 4, 3*s/4), c);
                drawLine(pos + Point(s / 2, 3 * s / 4), pos + Point(3*s/4, s), c);
                break;
            case 'R':
                drawLine(pos + Point(3 * s / 8, 0), pos + Point(3 * s / 8, s), c);
                drawArc(pos + Point(3 * s / 8, s / 4), s / 4, 3 * M_PI_2f, 5 * M_PI_2f, c);
                drawLine(pos + Point(3 * s / 8, s / 2), pos + Point(5 * s / 8, s), c);
                break;
            case 'S':
                drawArc(pos + Point(s / 2, s / 4), s / 4, M_PI_2f, M_TAUf, c);
                drawArc(pos + Point(s / 2, 3 * s / 4), s / 4, 3 * M_PI_2f, 3 * M_PIf, c);
                break;
            case 'T':
                drawLine(pos + Point(s / 2, 0), pos + Point(s / 2, s), c);
                drawLine(pos + Point(s / 4, 0), pos + Point(3 * s / 4, 0), c);
                break;
            case 'U':
                drawArc(pos + Point(s / 2, 3 * s / 4), s / 4, 0, M_PIf, c);
                drawLine(pos + Point(s / 4, 0), pos + Point(s / 4, 3 * s / 4), c);
                drawLine(pos + Point(3 * s / 4, 0), pos + Point(3 * s / 4, 3 * s / 4), c);
                break;
            case 'V':
                drawLine(pos + Point(s / 4, 0), pos + Point(s / 2, s), c);
                drawLine(pos + Point(3 * s / 4, 0), pos + Point(s / 2, s), c);
                break;
            case 'W':
                drawLine(pos + Point(s / 4, 0), pos + Point(3 * s / 8, s), c);
                drawLine(pos + Point(3 * s / 4, 0), pos + Point(5 * s / 8, s), c);
                drawLine(pos + Point(s / 2, s / 2), pos + Point(3 * s / 8, s), c);
                drawLine(pos + Point(s / 2, s / 2), pos + Point(5 * s / 8, s), c);
                break;
            case 'X':
                drawLine(pos + Point(s / 4, 0), pos + Point(3 * s / 4, s), c);
                drawLine(pos + Point(3 * s / 4, 0), pos + Point(s / 4, s), c);
                break;
            case 'Y':
                drawLine(pos + Point(s / 4, 0), pos + Point(s / 2, s / 2), c);
                drawLine(pos + Point(3 * s / 4, 0), pos + Point(s / 2, s / 2), c);
                drawLine(pos + Point(s / 2, s / 2), pos + Point(s / 2, s), c);
                break;
            case 'Z':
                drawLine(pos + Point(3 * s / 4, 0), pos + Point(s / 4, s), c);
                drawLine(pos + Point(s / 4, 0), pos + Point(3 * s / 4, 0), c);
                drawLine(pos + Point(s / 4, s), pos + Point(3 * s / 4, s), c);
                break;
            case '1':
                drawLine(pos + Point(s / 2, 0), pos + Point(s / 2, s), c);
                drawLine(pos + Point(s / 2, 0), pos + Point(s / 4, s / 4), c);
                break;
            case '2':
                drawArc(pos + Point(s / 2, s / 4), s / 4, M_PIf, 2 * M_PIf, c);
                drawLine(pos + Point(3 * s / 4, s / 4), pos + Point(s / 4, s), c);
                drawLine(pos + Point(s / 4, s), pos + Point(3 * s / 4, s), c);
                break;
            case '3':
                drawArc(pos + Point(s / 2, s / 4), s / 4, M_PIf, 5 * M_PI_2f, c);
                drawArc(pos + Point(s / 2, 3 * s / 4), s / 4, 3 * M_PI_2f, 3 * M_PIf, c);
                break;
            case '4':
                drawLine(pos + Point(3*s/4, 0), pos  + Point(3*s/4, s), c);
                drawLine(pos + Point(s/4, 3*s/4), pos  + Point(7*s/8, 3*s/4), c);
                drawLine(pos + Point(s/4, 3*s/4), pos  + Point(3*s/4, 0), c);
                break;
            case '5':
                drawLine(pos + Point(s/4, 0), pos  + Point(3*s/4, 0), c);
                drawLine(pos + Point(s/4, 0), pos  + Point(s/4, s/2), c);
                drawLine(pos + Point(s/4, s/2), pos  + Point(s/2, s/2), c);
                drawArc(pos+Point(s/2, 3*s/4), s/4, 3*M_PI_2f, 5*M_PI_2f, c);
                drawLine(pos + Point(s/4, s), pos  + Point(s/2, s), c);
                break;
            case '6':
                drawLine(pos + Point(s/4, s/4), pos  + Point(s/4, 3*s/4), c);
                drawArc(pos+Point(s/2, s/4), s/4, M_PIf, 2*M_PIf, c);
                drawArc(pos+Point(s/2, 3*s/4), s/4, 0, 2*M_PIf, c);
                break;
            case '7':
                drawLine(pos + Point(s/4, 0), pos  + Point(3*s/4, 0), c);
                drawLine(pos + Point(3*s/4, 0), pos  + Point(s/2, s), c);
                drawLine(pos + Point(4*s/8, s/2), pos  + Point(6*s/8, s/2), c);
                break;
            case '8':
                drawArc(pos+Point(s/2, s/4), s/4, 0, 2*M_PIf, c);
                drawArc(pos+Point(s/2, 3*s/4), s/4, 0, 2*M_PIf, c);
                break;
            case '9':
                drawLine(pos + Point(3*s/4, s/4), pos  + Point(3*s/4, 3*s/4), c);
                drawArc(pos+Point(s/2, 3*s/4), s/4, 0, M_PIf, c);
                drawArc(pos+Point(s/2, s/4), s/4, 0, 2*M_PIf, c);
                break;
            case '0':
                drawLine(pos + Point(3*s/4, s/4), pos  + Point(3*s/4, 3*s/4), c);
                drawArc(pos+Point(s/2, 3*s/4), s/4, 0, M_PIf, c);
                drawLine(pos + Point(s/4, s/4), pos  + Point(s/4, 3*s/4), c);
                drawArc(pos+Point(s/2, s/4), s/4, M_PIf, 2*M_PIf, c);
                break;
            case '-':
                drawLine(pos + Point(s/4, s/2), pos  + Point(3*s/4, s/2), c);
                break;
            case '+':
                drawLine(pos + Point(s/4, s/2), pos  + Point(3*s/4, s/2), c);
                drawLine(pos + Point(s/2, s/4), pos  + Point(s/2, 3*s/4), c);
                break;
            case '?':
                drawArc(pos+Point(s/2, s/4), s/4, M_PIf, 5*M_PI_2f, c);
                drawLine(pos + Point(s/2, s/2), pos  + Point(s/2, 3*s/4), c);
                drawArc(pos+Point(s/2, 15*s/16), s/16, 0, 2*M_PIf, c);
                break;
            case '!':
                drawLine(pos + Point(3*s/8, 0), pos  + Point(5*s/8, 0), c);
                drawLine(pos + Point(3*s/8, 0), pos  + Point(s/2, 3*s/4), c);
                drawLine(pos + Point(5*s/8, 0), pos  + Point(s/2, 3*s/4), c);
                drawArc(pos+Point(s/2, 15*s/16), s/16, 0, 2*M_PIf, c);
                break;
            case ' ':
                break;
            default:
                throw std::invalid_argument("symbol not supported");
        }
        pos += Point(s + betweenLetters, 0);
    }
}


