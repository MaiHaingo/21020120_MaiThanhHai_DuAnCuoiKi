#include "bullet.h"

// Constructor
Bullet::Bullet(float x, float y, float angle, float vx, float vy) {
    bullet_x = x;
    bullet_y = y;
    bullet_angle = angle;
    bullet_vx = vx;
    bullet_vy = vy;
}

float Bullet::getX() {return bullet_x;}
float Bullet::getY() {return bullet_y;}

// Hàm đổi toạ độ //
void Bullet::changeCoords(float c) {
    bullet_x = c;
}

// Hàm update vị trí của đạn
void Bullet::update(float dt) {
    bullet_x += bullet_vx * dt;
    bullet_y += bullet_vy * dt;
}

// Hàm vẽ đạn
void Bullet::draw(Graphics* graphic) {
    SDL_SetRenderDrawColor(graphic->getRenderer(), 0, 255, 255, 255);
    graphic->drawModel(graphic, bulletModel, bullet_x, bullet_y, bullet_angle, 1.0f);
    graphic->wrapCoordinates(bullet_x, bullet_y, bullet_x, bullet_y);
}