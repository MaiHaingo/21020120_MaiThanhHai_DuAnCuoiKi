/****************************************** MÀN HÌNH TRÒ CHƠI ******************************************/

#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include "InputManager.h"
#include "AudioManager.h"
#include "Timer.h"
#include "Texture.h"
#include "asteroids.h"
#include "ship.h"
#include "bullet.h"

class PlayScreen {
private:

    Timer* timer;
    InputManager* input;
    Graphics* graphic;
    AssetManager* asset_mng;
    AudioManager* audio_mng;
    
    Texture* bg; // ảnh nền
    
    Texture* score; // điểm
    Texture* life; // mạng

    Texture* MissionFailed; // khi chết
    Texture* messageQuit; // nếu quit

    Ship* player; // tàu

    int lives; // số mạng

    vector<Bullet> vecBullet; // đạn

    vector<Asteroid> vecAsteroid; // asteroid

    bool dead; // kiểm tra ship die hay chưa
    
    vector<Asteroid> newAsteroid; // một vector lưu lại các asteroid con khi tách ra

    int count; // biến đếm số điểm khi bắn trúng asteroid

public:

    PlayScreen();
    ~PlayScreen();

    void Update();

    void Render();

    bool checkDead();
};

#endif