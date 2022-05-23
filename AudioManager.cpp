#include "AudioManager.h"

// Tạo ra một instance duy nhất, nếu đã có rồi thì trả về instance //
AudioManager* AudioManager::Instance = NULL;
AudioManager* AudioManager::getInstance() {
    if (Instance == NULL) Instance = new AudioManager();
    return Instance;
}

// Huỷ instance //
void AudioManager::Release() {
    delete Instance;
    Instance = NULL;
}


// Constructor //
AudioManager::AudioManager() {
    am = AssetManager::getInstance();
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
        printf("Mixer Initialization Error: %s\n", Mix_GetError());
    }
}


// Destructor // 
AudioManager::~AudioManager() {
    am = NULL;
    Mix_Quit();
}

// Phát audio //
void AudioManager::PlayAudio(string filename, int loops) {
    Mix_PlayMusic(am->getAudio(filename), loops);
}

// Dừng audio //
void AudioManager::PauseAudio() {
    if (Mix_PlayingMusic() != 0) {
        Mix_PauseMusic();
    }
}


// Tiếp tục audio //
void AudioManager::ResumeAudio() {
    if (Mix_PausedMusic() != 0) {
        Mix_ResumeMusic();
    }
}

// Phát SFX //
void AudioManager::PlaySFX(string filename, int loops, int channel) {
    Mix_PlayChannel(channel, am->getSFX(filename), loops);
}