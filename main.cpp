#include <iostream>
#include <cmath>
#include <sfml/Graphics.hpp>

int main() {
    //  define all variables
    int width = 800; // pixels
    int height = 600; // pixels

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow(sf::VideoMode(width, height), "donut_sim", sf::Style::Default, settings);

    int ScreenCentre[3];
    int CameraFocus[3];
    int PointtoDisplay[3];

    int x, y, z, f;
    int v[3], d[3];

    for (int i = 0;i < 3;i++) {
        v[i] = PointtoDisplay[i] - ScreenCentre[i];
        d[i] = CameraFocus[i] - ScreenCentre[i];
    }
    y = sqrt(pow(v[1] * d[2] - d[1] * v[2], 2) + pow(v[0] * d[2] + v[2] + d[0], 2) + pow(v[0] * d[1] + v[1] * d[0], 2)) / sqrt(pow(d[0], 2) + pow(d[1], 2) + pow(d[2], 2));

    int Tclo;

    Tclo = (PointtoDisplay[0] - ScreenCentre[0]) * d[0] + (PointtoDisplay[1] - ScreenCentre[1]) * d[1] + (PointtoDisplay[2] - ScreenCentre[2]) * d[2];

    z = sqrt(pow(CameraFocus[0] - (ScreenCentre[0] + Tclo * d[0]), 2) + pow(CameraFocus[1] - (ScreenCentre[1] + Tclo * d[1]), 2) + pow(CameraFocus[2] - (ScreenCentre[2] + Tclo * d[2]), 2));

    f = sqrt(pow(CameraFocus[0] - ScreenCentre[0], 2) + pow(CameraFocus[1] - ScreenCentre[1], 2) + pow(CameraFocus[2] - ScreenCentre[2], 2));

    int camX, camY;

    camY = f * y / z;
}