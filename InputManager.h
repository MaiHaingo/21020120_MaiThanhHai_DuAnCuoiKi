/****************************************** THƯ VIỆN XỬ LÍ ĐẦU VÀO ******************************************/

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL2/SDL.h>

class InputManager {

private:
    static InputManager* Instance;

    const Uint8* KeyBoardStates;

public:

    static InputManager* getInstance();
    static void Release();

    bool KeyDown(SDL_Scancode scanCode);

    void Update();

private:

    InputManager();
    ~InputManager();
};

#endif