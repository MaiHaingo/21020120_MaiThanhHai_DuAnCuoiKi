/****************************************** THƯ VIỆN XỬ LÍ AUDIO ******************************************/

#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include "AssetManager.h"

class AudioManager {

private:

    static AudioManager* Instance;

    AssetManager* am;

public:

    static AudioManager* getInstance();
    static void Release();
    
    void PlayAudio(string filename, int loops = -1); // loops = -1 audio bật vô hạn; loops = 0 audio bật 1 lần
    void PauseAudio();
    void ResumeAudio();

    void PlaySFX(string filename, int loops = 0, int channel = 0);

private:

    AudioManager();
    ~AudioManager();

};

#endif