/****************************************** HÀM QUẢN LÍ CÁC MÀN HÌNH ******************************************/


#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "StartScreen.h"
#include "PlayScreen.h"
#include "InputManager.h"

class ScreenManager {

private:
    enum SCREENS {Start, Play}; // có 2 màn hình: Start & Play

    SCREENS currentScreen; // biến lưu màn hình hiện tại

    static ScreenManager* Instance;

    InputManager* input;

    StartScreen* startScreen;

    PlayScreen* playScreen;

    bool quit;


public:

    static ScreenManager* getInstance();

    static void Release();

    void Update();

    void Render();

    bool checkQuit();

    void changeQuit(bool change);

private:

    ScreenManager();
    ~ScreenManager();
};

#endif