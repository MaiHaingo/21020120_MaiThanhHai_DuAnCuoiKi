/****************************************** THƯ VIỆN QUẢN LÍ TRÒ CHƠI ******************************************/

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "InputManager.h"
#include "Texture.h"
#include "Timer.h"
#include "AudioManager.h"
#include "ScreenManager.h"
#include "asteroids.h"
#include "ship.h"
#include "bullet.h"

class GameManager {

private:

    static GameManager* Instance;

    Graphics* graphic; 

    AssetManager* am; 

    InputManager* im; 

    AudioManager* am_audio; 
    
    ScreenManager* sm;

    Timer* t; 

    SDL_Event e; 

public:

    static GameManager* getInstance();

    static void Release();

    void Loop();


private:

    GameManager();
    ~GameManager(); 

};

#endif