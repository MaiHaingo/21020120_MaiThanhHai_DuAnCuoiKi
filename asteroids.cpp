#include "asteroids.h"


// Constructor //
Asteroid::Asteroid(float x, float y, float angle, float vx, float vy, float size) {
    asteroid_x = x; 
    asteroid_y = y; 
    asteroid_angle = angle; 
    asteroid_vx = vx; 
    asteroid_vy = vy; 
    this->size = size;
}

float Asteroid::getX() { return asteroid_x;}

float Asteroid::getY() { return asteroid_y;}

float Asteroid::getSize() { return size;}

// Hàm update vị trí và góc //
void Asteroid::update(float dt, Graphics *graphic) {
    asteroid_x += asteroid_vx * dt;
    asteroid_y += asteroid_vy * dt;
    asteroid_angle += 1.0f * dt;
    graphic->wrapCoordinates(asteroid_x, asteroid_y, asteroid_x, asteroid_y);
}


// Hàm tạo ra mô hình asteroids //
void Asteroid::createAsteroidModel() {
    for (int i = 0; i < verts; i++) {
        radius = 10.0f * size; // giả sử lấy bán kính là 10
        int seg = ((float)i / (float)verts) * 2 * PI; // từ 20 đỉnh ta chia ra thành 20 phần của hình tròn và đánh dấu toạ độ lại
        asteroidModel.push_back(std::make_pair(radius * sin(seg), radius * cos(seg))); // x = R*sin; y = R*cos
    } 
}

// Hàm vẽ asteroid //
void Asteroid::draw(Graphics *graphic) {
    Asteroid::createAsteroidModel();
    SDL_SetRenderDrawColor(graphic->getRenderer(), 255, 255, 255, 255); // set color
    graphic->drawModel(graphic, asteroidModel, asteroid_x, asteroid_y, asteroid_angle, size);
}

