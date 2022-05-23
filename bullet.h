/****************************************** THƯ VIỆN BULLET ******************************************/

#ifndef BULLET_H
#define BULLET_H

#include "Graphics.h"

class Bullet {

private:

    float bullet_x;
    float bullet_y;
    float bullet_angle;
    float bullet_vx;
    float bullet_vy;

public:

    Bullet(float x, float y, float angle, float vx, float vy);

    float getX();
    float getY();

    void changeCoords(float c);

    bool handleEvent(SDL_Event& e);

    void update(float dt);

    vector<pair<float, float>> bulletModel = {
        {0.0f, 0.0f},
        {0.0f, 3.0f}
    };

    void draw(Graphics *graphic);
    
};

#endif