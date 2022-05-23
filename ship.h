/****************************************** THƯ VIỆN SHIP ******************************************/

#ifndef SHIP_H
#define SHIP_H

#include "Graphics.h"
#include <math.h>
#include "InputManager.h"


class Ship {

private: 
    float ship_x;
    float ship_y;
    float ship_angle;
    float ship_vx;
    float ship_vy;

public: 
    Ship();
    float getX();
    float getY();
    float getAngle();

    vector<pair<float, float>> shipModel = {
        {0.0f, -15.0f},
        {-5.0f, 5.0f},
        {5.0f, 5.0f}
    };

    void draw(Graphics* graphic);

    void handleEvent(InputManager* im);
    void update(float dt, Graphics* graphic);
    void Reset();
};

#endif