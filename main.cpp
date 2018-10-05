#include <iostream>
#include "Color.h"

using namespace std;

int main() {
    vector<double> Coords = {123, 9, 67};
    Color RGB("RGB", Coords);
    Color CMY = RGB.RGBtoCMY();
    Color CMYK = RGB.RGBtoCMYK();
    Color HSL = RGB.RGBtoHSL();
    Color HSV = RGB.RGBtoHSV();
    Color XYZ = RGB.RGBtoXYZ();

    vector<Color> colors = {RGB, CMY, CMYK, HSL, HSV, XYZ};
    for (auto cl : colors) {
        cl.print();
    }
    cout << endl;

    string model;
    cout << "Input color model: ";
    cin >> model;
    cout << "Input color coordinates, satisfying following constraints: "
            "\n RGB  : [0, 255]"
            "\n CMY  : [0,1]"
            "\n CMYK : [0,1]"
            "\n HSL  : H   : [0,360)"
            "\n        S, L: [0,1] "
            "\n HSV  : H   : [0,360)"
            "\n        S, V: [0,1] ";
    vector<double> Coords2;
    double input;
    for (int i = 0; i < model.length(); i++){
        cin >> input;
        Coords2.push_back(input);
    }
    Color ColorA(model, Coords2);
    ColorA = ColorA.toRGB();
    Color CMY1 = ColorA.RGBtoCMY();
    Color CMYK1 = ColorA.RGBtoCMYK();
    Color HSL1 = ColorA.RGBtoHSL();
    Color HSV1 = ColorA.RGBtoHSV();
    Color XYZ1 = ColorA.RGBtoXYZ();

    vector<Color> colors1 = {ColorA, CMY1, CMYK1, HSL1, HSV1, XYZ1};
    for (auto cl : colors1) {
        cl.print();
    }
    cout << endl;


    return 0;
}