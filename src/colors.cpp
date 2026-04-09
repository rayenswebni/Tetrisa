#include "colors.h"

const Color darkGrey = {26, 31, 40, 255}; // darkgrey
const Color red = {255, 0, 0, 255};
const Color darkRed2 = {96, 19, 0, 255};
const Color blue = {70, 130, 180, 255}; // Blue
const Color green = {50, 205, 50, 255};// Green
const Color yellow = {255, 215, 0, 255};// Yellow
const Color purple = {138, 43, 226, 255};// Purple
const Color cyan = {0, 255, 255, 255};// Cyan
const Color orange = {255, 140, 0, 255};// Orange

std::vector<Color> GetCellColors() {
    return {
        darkGrey,
        darkRed2,
        blue,
        green,
        yellow,
        purple,
        cyan,
        orange,
        red 
    };
}