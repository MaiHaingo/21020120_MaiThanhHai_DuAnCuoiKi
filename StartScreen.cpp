#include "StartScreen.h"

// Constructor //
StartScreen::StartScreen() {
    blackhole = new Texture("blackhole.png", Graphics::SCREEN_WIDTH / 2, 0, Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
    Logo = new Texture("VoyagerX", "De-Valencia.ttf", 72, Graphics::SCREEN_WIDTH / 5, 90, 360, 60);
    Start = new Texture("Start", "De-Valencia.ttf", 72, Graphics::SCREEN_WIDTH / 5, 170, 180, 30);
    Exit = new Texture("Exit", "De-Valencia.ttf", 72, Graphics::SCREEN_WIDTH / 5, 210, 180, 30);
    cursor = new Texture("cursor.png", 100, 175, 15, 15);
    input = InputManager::getInstance();
    select = 0; // Start sẽ là 0, Play sẽ là 1 

}


// Destructor //
StartScreen::~StartScreen() {
    delete blackhole;
    blackhole = NULL;

    delete Logo;
    Logo = NULL;

    delete Start;
    Start = NULL;

    delete Exit;
    Exit = NULL;

    delete cursor;
    cursor = NULL;

}

// Hàm update //
void StartScreen::Update() {
    if (input->KeyDown(SDL_SCANCODE_UP)) {
        cursor->changeCoords(175);
        select = 0;
    }
    else if (input->KeyDown(SDL_SCANCODE_DOWN)) {
        cursor->changeCoords(215);
        select = 1;
    }
}

// Hàm render //
void StartScreen::Render() {
    
    blackhole->Render();
    Logo->Render();
    Start->Render();
    Exit->Render();
    cursor->Render();
    
}

// trả vè số thứ tự của màn hình //
int StartScreen::returnSelect() {
    return select;
}