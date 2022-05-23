#include "Timer.h"

// Tạo ra một instance duy nhất, nếu đã có rồi thì trả về instance //
Timer* Timer::Instance = NULL;
Timer* Timer::getInstance() {

    if (Instance == NULL) Instance = new Timer();
    return Instance;

}

// Huỷ instance //
void Timer::Release() {

    delete Instance;
    Instance = NULL; 

}

// Constructor //
Timer::Timer() {

    Reset();
    ElapsedTicks = 0;
    DeltaTime = 0.0f;

}

// Reset timer //
void Timer::Reset() {

    StartTicks = SDL_GetTicks();
    
}

// Lấy ra delta time //
float Timer::getDeltaTime() {

    return DeltaTime;

}

// Update timer //
void Timer::Update() {
    ElapsedTicks = SDL_GetTicks() - StartTicks;
    DeltaTime = ElapsedTicks * 0.001f;
}