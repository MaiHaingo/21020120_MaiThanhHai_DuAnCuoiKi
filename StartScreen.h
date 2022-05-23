/****************************************** MÀN HÌNH START ******************************************/

#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Texture.h"
#include "InputManager.h"

class StartScreen {

private:
    Texture* blackhole; // ảnh nền menu
    Texture* Logo; // logo
    Texture* Start; // chế độ chơi
    Texture* Exit; // chế độ thoát
    Texture* cursor; // con trỏ 
    InputManager* input; // đầu vào
    int select; // đánh số màn hình


public:

    StartScreen();
    ~StartScreen();

    void Update();

    void Render();

    int returnSelect();
};

#endif