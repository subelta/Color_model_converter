#include "Color.h"

Color :: Color() {}

Color :: Color(string mod, vector<double> Coord) {
    model = mod;
    Coordinates = Coord;
}

void Color :: print() {
    cout << model <<": ";
    for (auto v : Coordinates) {
        cout << v <<" ";
    }
    cout << endl;
}

Color Color :: CMYtoRGB() {
    Color NewColor;
    for (int i = 0; i < 3; i++) {
        double buff = 255 * (1 - Coordinates[i]);
        NewColor.Coordinates.push_back(buff);
    }
    NewColor.model = "RGB";
    return NewColor;
}

Color Color :: CMYKtoRGB() {
    Color NewColor;
    double R = 255 *(1 - Coordinates[0]) * (1 - Coordinates[3]);
    double G = 255 *(1 - Coordinates[1]) * (1 - Coordinates[3]);
    double B = 255 *(1 - Coordinates[2]) * (1 - Coordinates[3]);
    NewColor.Coordinates = {round(R), round(G), round(B)};
    NewColor.model = "RGB";
    return NewColor;
}

Color Color :: HSLtoRGB() {
    double H = Coordinates[0];
    double S = Coordinates[1];
    double L = Coordinates[2];
    double Hh = H / 60;

    double C = (1 - abs((2 * L) - 1)) * S;
    double X = C * (1 - abs(fmodf(Hh, 2.0) - 1));
    double m = L - C / 2;

    double Rr = 0, Gg = 0, Bb = 0;
    if ((0 <= H) && (H < 60)) {
        Rr = C; Gg = X; Bb = 0;
    }
    if ((60 <= H) && (H < 120)) {
        Rr = X; Gg = C; Bb = 0;
    }
    if ((120 <= H) && (H < 180)) {
        Rr = 0; Gg = C; Bb = X;
    }
    if ((180 <= H) && (H < 240)) {
        Rr = 0; Gg = X; Bb = C;
    }
    if ((240 <= H) && (H < 300)) {
        Rr = X; Gg = 0; Bb = C;
    }
    if ((300 <= H) && (H < 360)) {
        Rr = C; Gg = 0; Bb = X;
    }
    double R = round((Rr + m) * 255);
    double G = round((Gg + m) * 255);
    double B = round((Bb + m) * 255);
    Color NewColor("RGB", {R, G, B});
    return NewColor;
}

Color Color :: HSVtoRGB() {
    double H = Coordinates[0];
    double S = Coordinates[1];
    double V = Coordinates[2];
    double Hh = H / 60;

    double C = V * S;
    double X = C * (1 - abs(fmodf(Hh, 2.0) - 1));
    double m = V - C;

    double Rr = 0, Gg = 0, Bb = 0;
    if ((0 <= H) && (H < 60)) {
        Rr = C; Gg = X; Bb = 0;
    }
    if ((60 <= H) && (H < 120)) {
        Rr = X; Gg = C; Bb = 0;
    }
    if ((120 <= H) && (H < 180)) {
        Rr = 0; Gg = C; Bb = X;
    }
    if ((180 <= H) && (H < 240)) {
        Rr = 0; Gg = X; Bb = C;
    }
    if ((240 <= H) && (H < 300)) {
        Rr = X; Gg = 0; Bb = C;
    }
    if ((300 <= H) && (H < 360)) {
        Rr = C; Gg = 0; Bb = X;
    }
    double R = round((Rr + m) * 255);
    double G = round((Gg + m) * 255);
    double B = round((Bb + m) * 255);
    Color NewColor("RGB", {R, G, B});
    return NewColor;
}

Color Color :: toRGB() {
    Color RGB(model, Coordinates);
    if (model == "CMY") {
        RGB = CMYtoRGB();
    }
    if (model == "CMYK") {
        RGB = CMYKtoRGB();
    }
    if (model == "HSL") {
        RGB = HSLtoRGB();
    }
    if (model == "HSV") {
        RGB = HSVtoRGB();
    }
    return RGB;
}

Color Color :: RGBtoCMY() {
    double C = 1 - ( Coordinates[0] / 255 );
    double M = 1 - ( Coordinates[1] / 255 );
    double Y = 1 - ( Coordinates[2] / 255 );
    Color NewColor("CMY", {C, M, Y});
    return NewColor;
}

Color Color :: RGBtoCMYK() {
    double Rr = Coordinates[0] / 255;
    double Gg = Coordinates[1] / 255;
    double Bb = Coordinates[2] / 255;

    double K = 1 - max(max(Rr, Gg), Bb);
    double C = (1 - Rr - K) / (1 - K);
    double M = (1 - Gg - K) / (1 - K);
    double Y = (1 - Bb - K) / (1 - K);
    Color NewColor("CMYK", {C, M, Y, K});
    return NewColor;
}

Color Color :: RGBtoHSL() {
    double Rr = Coordinates[0] / 255;
    double Gg = Coordinates[1] / 255;
    double Bb = Coordinates[2] / 255;

    double C_max = max(max(Rr, Gg), Bb);
    double C_min = min(min(Rr, Gg), Bb);
    double delta = C_max - C_min;

    double H = 0;
    if (delta == 0) {
        H = 0;
    }
    if (C_max == Rr) {
        H = 60 * fmod(((Gg - Bb) / delta) , 6.0);
    }
    if (C_max == Gg) {
        H = 60 * (((Bb - Rr) / delta) + 2);
    }
    if (C_max == Bb) {
        H = 60 * (((Rr - Gg) / delta) + 4);
    }
    if (H < 0) {
        H += 360;
    }

    double L = (C_max + C_min) / 2;

    double S;
    if (delta == 0) {
        S = 0;
    }
    else {
        S = delta / (1 - abs((2 * L) - 1));
    }
    Color NewColor("HSL",{H, S, L});
    return NewColor;
}

Color Color :: RGBtoHSV() {
    double Rr = Coordinates[0] / 255;
    double Gg = Coordinates[1] / 255;
    double Bb = Coordinates[2] / 255;

    double C_max = max(max(Rr, Gg), Bb);
    double C_min = min(min(Rr, Gg), Bb);
    double delta = C_max - C_min;

    double H = 0;
    if (delta == 0) {
        H = 0;
    }
    if (C_max == Rr) {
        H = 60 * fmod(((Gg - Bb) / delta) , 6.0);
    }
    if (C_max == Gg) {
        H = 60 * (((Bb - Rr) / delta) + 2);
    }
    if (C_max == Bb) {
        H = 60 * (((Rr - Gg) / delta) + 4);
    }
    if (H < 0) {
        H += 360;
    }

    double S;
    if (delta == 0) {
        S = 0;
    }
    else {
        S = delta / C_max;
    }

    double V = C_max;

    Color NewColor("HSV", {H, S, V});
    return NewColor;
}

Color Color :: RGBtoXYZ() {
    vector<double> RGBrgb = {Coordinates[0] / 255,
                             Coordinates[1] / 255,
                             Coordinates[2] / 255};
    double a = 0.055;
    for (int C = 0; C < 3; C++) {
        if (RGBrgb[C] <= 0.04045) {
            RGBrgb[C] = RGBrgb[C] / 12.92;
        }
        else {
            RGBrgb[C] = pow(((RGBrgb[C] + a) / (1 + a)), 2.4);
        }
    }

    double X = 0.4124 * RGBrgb[0] + 0.3576 * RGBrgb[1] + 0.1805 * RGBrgb[2];
    double Y = 0.2126 * RGBrgb[0] + 0.7152 * RGBrgb[1] + 0.0722 * RGBrgb[2];
    double Z = 0.0193 * RGBrgb[0] + 0.1192 * RGBrgb[1] + 0.9505 * RGBrgb[2];
    Color NewColor("XYZ", {100 * X,100 * Y,100 * Z});
    return NewColor;
}



