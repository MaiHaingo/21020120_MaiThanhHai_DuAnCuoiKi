#include "GameManager.h"

using namespace std;

// Tạo ra một instance duy nhất, nếu đã có rồi thì trả về instance //
GameManager* GameManager::Instance = NULL;
GameManager* GameManager::getInstance() {

    if (Instance == NULL) {
        Instance = new GameManager();
    }

    return Instance;
} 

// Huỷ instance // 
void GameManager::Release() {
    delete Instance;
    Instance = NULL;
}

// Constructor //
GameManager::GameManager() {

    graphic = Graphics::getInstance(); // đồ hoạ

    if (!Graphics::isInitialized()) {
        sm->changeQuit(true);
    }

    am = AssetManager::getInstance(); // tài nguyên

    im = InputManager::getInstance(); // đầu vào

    am_audio = AudioManager::getInstance(); // âm thanh

    t = Timer::getInstance(); // thời gian

    sm = ScreenManager::getInstance(); // màn hình

}

// Destructor //
GameManager::~GameManager() {

    ScreenManager::Release();
    sm = NULL;
    
    AssetManager::Release();
    am = NULL;

    InputManager::Release();
    im = NULL;

    AudioManager::Release();
    am_audio = NULL;

    Graphics::Release();
    graphic = NULL;

    Timer::Release();
    t = NULL;

}


// Game loop: vòng lặp trò chơi //
void GameManager::Loop() {
    
    // theme audio
    am_audio->PlayAudio("Interstellar.wav", -1);

    //game loop
    while (!sm->checkQuit()) {

        // update timer and calculate delta time
        t->Update();
        
        // hanlde keyboard input
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                sm->changeQuit(true);
            } 
        }

        // giới hạn fps
        if (t->getDeltaTime() >= (1.0f / FRAME_RATE)) {

            // reset timer
            t->Reset();

            // update input
            im->Update();
            sm->Update(); // for screens

            // clear screen
            graphic->ClearBackBuffer();

            //render
            sm->Render();
                
            //show to screen
            graphic->Render();  

        }
    }
}


