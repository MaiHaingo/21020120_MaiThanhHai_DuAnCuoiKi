/****************************************** THƯ VIỆN ASTEROIDS ******************************************/

#ifndef ASTEROID_H
#define ASTEROID_H

#include "Graphics.h" 

class Asteroid {

private:

    float asteroid_x, asteroid_y; 
    float asteroid_angle;
    float asteroid_vx, asteroid_vy;
    int size;

public:

    Asteroid(float x, float y, float angle, float vx, float vy, float size); 
    
    float getX();
    float getY();
    float getSize();


    void update(float dt, Graphics *graphic);
    
    vector<pair<float, float>> asteroidModel;
    int verts = 20;
    int radius = 5.0f;
    void createAsteroidModel();

    void draw(Graphics *graphic);
    
};

#endif