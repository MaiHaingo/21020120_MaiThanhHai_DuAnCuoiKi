#include "ship.h"

// Constructor //
Ship::Ship() {
    ship_x = Graphics::SCREEN_WIDTH * 0.5f;
    ship_y = Graphics::SCREEN_HEIGHT * 0.5f;
    ship_angle = 0.0f;
    ship_vx = 0.0f;
    ship_vy = 0.0f;
}

float Ship::getX() {return ship_x;}
float Ship::getY() {return ship_y;}
float Ship::getAngle() {return ship_angle;}

// Hàm vẽ //
void Ship::draw(Graphics* graphic) {
    SDL_SetRenderDrawColor(graphic->getRenderer(), 255, 255, 255, 255);
    graphic->drawModel(graphic, shipModel, ship_x, ship_y, ship_angle, 1.0f);
}

// Điều khiển tàu //  
void Ship::handleEvent(InputManager* im) {
    // nếu ấn nút

        // thay đổi vận tốc
        if (im->KeyDown(SDL_SCANCODE_UP)) 
        {
            ship_vx += sin(ship_angle) * 10.0f;
            ship_vy += -cos(ship_angle) * 10.0f;

        }

        else if (im->KeyDown(SDL_SCANCODE_LEFT)) 
        {
            ship_angle -= 0.2f; 

        }

        else if (im->KeyDown(SDL_SCANCODE_RIGHT)) 
        {
            ship_angle += 0.2f; 

        }
             
}

// Hàm update vị trí tàu //
void Ship::update(float dt, Graphics* graphic) {
    ship_x += ship_vx * dt;
    ship_y += ship_vy * dt;
    graphic->wrapCoordinates(ship_x, ship_y, ship_x, ship_y);
}

// Hàm reset lại tàu về tâm màn hình //
void Ship::Reset() {
    ship_x = Graphics::SCREEN_WIDTH * 0.5f;
    ship_y = Graphics::SCREEN_HEIGHT * 0.5f;
    ship_angle = 0.0f;
    ship_vx = 0.0f;
    ship_vy = 0.0f;
}