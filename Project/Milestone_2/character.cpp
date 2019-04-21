#include "character.hpp"

void character::changex(int newx) {
    x = newx;
}

void character::changey(int newy) {
    y = newy;
}

void character::plusy (int newy){
    y += newy;
}

void character::minusy (int newy){
    y -=m newy;
}

void character::plusx (int newx){
    x += newx;
}

void character::minusx (int newx){
    x -= newx;
}

int character::getx() {
    return x;
}

int character::gety() {
    return y;
}

