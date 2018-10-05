#ifndef C_GRAPHICS_COLOR_H
#define C_GRAPHICS_COLOR_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Color {
public:
    string model = "null";
    vector<double> Coordinates;
    Color();
    Color(string mod, vector<double> Coord);

    void print();

    Color CMYtoRGB();
    Color CMYKtoRGB();
    Color HSLtoRGB();
    Color HSVtoRGB();
    Color toRGB();

    Color RGBtoCMY();
    Color RGBtoCMYK();
    Color RGBtoHSL();
    Color RGBtoHSV();
    Color RGBtoXYZ();
};



#endif //C_GRAPHICS_COLOR_H
