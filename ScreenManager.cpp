#include "ScreenManager.h"

// Tạo ra một instance duy nhất, nếu đã có rồi thì trả về instance //
ScreenManager* ScreenManager::Instance = NULL;
ScreenManager* ScreenManager::getInstance() {
    if (Instance == NULL) Instance = new ScreenManager();
    return Instance;
}

void ScreenManager::Release() {
    delete Instance;
    Instance = NULL;
}

// Huỷ instance //
ScreenManager::ScreenManager() {

    input = InputManager::getInstance();

    startScreen = new StartScreen();

    playScreen = new PlayScreen();

    currentScreen = Start;

    quit = false;
}

// Destructor // 
ScreenManager::~ScreenManager() {

    input = NULL;

    delete startScreen;
    startScreen = NULL;

    delete playScreen;
    playScreen = NULL;
}

// Hàm update các màn hình //
void ScreenManager::Update() {
    switch (currentScreen) {
    
    // màn hình Start
    case Start:
        startScreen->Update();
        if (input->KeyDown(SDL_SCANCODE_RETURN) && startScreen->returnSelect() == 0) {
            currentScreen = Play;
        }

        if (input->KeyDown(SDL_SCANCODE_RETURN) && startScreen->returnSelect() == 1) {
            quit = true;
        }
        break;

    // màn hình Play
    case Play:
        playScreen->Update();
        if (playScreen->checkDead() == true && input->KeyDown(SDL_SCANCODE_ESCAPE)) {
            playScreen = new PlayScreen();
            quit = true; // exit
        }
        break;
    }
}

// Hàm render //
void ScreenManager::Render() {
    switch (currentScreen) {
        
    case Start:
        startScreen->Render();
        break;

    case Play:
        playScreen->Render();

        break;
    }
}

bool ScreenManager::checkQuit() {
    return quit;
}

void ScreenManager::changeQuit(bool change) {
    quit = change;
} 