#include "InputManager.h"

// Tạo ra một instance duy nhất, nếu đã có rồi thì trả về instance //
InputManager* InputManager::Instance = NULL;
InputManager* InputManager::getInstance() {
    if (Instance == NULL) Instance = new InputManager();
    return Instance;
}

// Huỷ instance //
void InputManager::Release() {
    delete Instance;
    Instance = NULL;

}

// Constructor //
InputManager::InputManager() {

}

// Destructor //
InputManager::~InputManager() {

}

// Kiểm tra đang nhấn phím nào //
bool InputManager::KeyDown(SDL_Scancode scanCode) {

    return KeyBoardStates[scanCode];

}

// Đưa các phím input vào một mảng //
void InputManager::Update() {

    KeyBoardStates = SDL_GetKeyboardState(NULL);

}

