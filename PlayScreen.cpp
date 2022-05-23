#include "PlayScreen.h"

// Constructor //
PlayScreen::PlayScreen() {

    timer = Timer::getInstance();
    input = InputManager::getInstance();
    graphic = Graphics::getInstance();
    asset_mng = AssetManager::getInstance();
    audio_mng = AudioManager::getInstance();

    player = new Ship();

    lives = 3;

    for (int i = 0; i < 5; i++) {
        Asteroid mom(graphic->random(0, 800), graphic->random(0, 600), graphic->random(0, 360), graphic->random(-100, 100), graphic->random(-100, 100), 2.0f);
        vecAsteroid.push_back(mom);
    }

    bool dead = false; // kiểm tra ship die hay chưa

    count = 0;

    bg = new Texture("space2.png", Graphics::SCREEN_WIDTH / 2, 0, Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
    MissionFailed = new Texture("MISSION FAILED", "De-Valencia.ttf", 72, graphic->SCREEN_WIDTH / 2, graphic->SCREEN_HEIGHT / 5, 700, 100);
    messageQuit = new Texture("PRESS 'ESC' TO QUIT", "De-Valencia.ttf", 72, graphic->SCREEN_WIDTH / 2, graphic->SCREEN_HEIGHT / 2, 350, 50);
    score = new Texture("SCORE:", "De-Valencia.ttf", 72, 80, 0, 150, 30);
    life = new Texture("LIVES:", "De-Valencia.ttf", 72, 80, 30, 150, 30);
}


PlayScreen::~PlayScreen() {

    timer = NULL;
    input = NULL;
    graphic = NULL;
    asset_mng = NULL;
    audio_mng = NULL;

    delete bg;
    bg = NULL;

    delete score;
    score = NULL;

    delete life;
    life = NULL;

    delete MissionFailed;
    MissionFailed = NULL;

    delete player;
    player = NULL;

    vecAsteroid.clear();
    vecBullet.clear();
    
}

void PlayScreen::Update() {

    score = new Texture("SCORE:" + std::to_string(count), "De-Valencia.ttf", 72, 80, 0, 150, 30);
    life = new Texture("LIVES:" + std::to_string(lives), "De-Valencia.ttf", 72, 80, 30, 150, 30);

    // update input //
    player->handleEvent(input); // for player

    // 'SPACE' to fire
    if (input->KeyDown(SDL_SCANCODE_SPACE)) { 

        Bullet b(player->getX(), player->getY(), player->getAngle(), 500.0f * sin(player->getAngle()), -500.0f * cos(player->getAngle()));
        vecBullet.push_back(b);
        audio_mng->PlaySFX("fireSFX.wav");

    }

    // update motion //
    player->update(timer->getDeltaTime(), graphic); // update coordinates for player
            
    //update asteroids (with player)
    for (int i = 0; i < vecAsteroid.size(); i++) {

        vecAsteroid[i].update(timer->getDeltaTime(), graphic);

        // check va chạm với ship
        if (graphic->checkCollision(vecAsteroid[i].getX(), vecAsteroid[i].getY(), player->getX(), player->getY(), vecAsteroid[i].radius) == true) {

            audio_mng->PlaySFX("shipExplode.wav", 0, 1);
            lives -= 1; // giảm mạng đi 1
            player->Reset(); // reset người chơi về giữa màn hình

            // tách đôi asteroid
            if (vecAsteroid[i].getSize() > 1.0f) {

                Asteroid child1(vecAsteroid[i].getX(), vecAsteroid[i].getY(), graphic->random(0, 360), graphic->random(-100.0f, 100.0f), graphic->random(-100.0f, 100.0f), 1.0f);
                Asteroid child2(vecAsteroid[i].getX(), vecAsteroid[i].getY(), graphic->random(0, 360), graphic->random(-100.0f, 100.0f), graphic->random(-100.0f, 100.0f), 1.0f);
                newAsteroid.push_back(child1);
                newAsteroid.push_back(child2);

            }

            // xoá asteroid mẹ bị bắn trúng khỏi vector
            vecAsteroid.erase(vecAsteroid.begin() + i);
        }
    }

    //update bullet (with asteroid)
    for (int i = 0; i < vecBullet.size(); i++) {

        vecBullet[i].update(timer->getDeltaTime());

        // xoá bullet nếu out màn hình
        if (vecBullet.size() > 0) { // kiểm tra nếu còn đạn
            // hàm remove_if sẽ đưa những phần tử ko thoả mãn if về cuối mảng, sau đó trả về iterator tới mảng đó
            auto i = remove_if(vecBullet.begin(), vecBullet.end(), 
                    // lambda function: gồm 3 phần 
                    // []: capture list -> capture một biến, cho nó quyền truy cập bên trong lambda (ở đây sẽ capture reference)
                    // (): parameter list -> tham số của hàm lambda (ở đây là đạn)
                    // {}: function body (thân hàm) -> ở đây là logic check xem bullet ra ngoài màn hình chưa
                    // return bool (true nếu thoả mãn điều kiện và ngược lại)
                    [&](Bullet d){ return (d.getX() < 1 || d.getY() < 1 || d. getX() >= graphic->SCREEN_WIDTH|| d.getY() >= graphic->SCREEN_HEIGHT); });
            
            // xoá đạn
            if ( i != vecBullet.end()) vecBullet.erase(i);
        }

        // với mỗi bullet check va chạm với từng asteroid
        for (int j = 0; j < vecAsteroid.size(); j++) {
            // nếu va chạm
            if (graphic->checkCollision(vecAsteroid[j].getX(), vecAsteroid[j].getY(), vecBullet[i].getX(), vecBullet[i].getY(), vecAsteroid[j].radius)) {
                // SFX
                audio_mng->PlaySFX("explosion2.wav", 0, 2);
                        
                // huỷ bullet
                vecBullet[i].changeCoords(-1000);

                // tách đôi asteroid
                if (vecAsteroid[j].getSize() > 1.0f) {
                    Asteroid child3(vecAsteroid[j].getX(), vecAsteroid[j].getY(), graphic->random(0, 360), graphic->random(-100.0f, 100.0f), graphic->random(-100.0f, 100.0f), 1.0f);
                    Asteroid child4(vecAsteroid[j].getX(), vecAsteroid[j].getY(), graphic->random(0, 360), graphic->random(-100.0f, 100.0f), graphic->random(-100.0f, 100.0f), 1.0f);
                    newAsteroid.push_back(child3);
                    newAsteroid.push_back(child4);

                    // nếu có asteroid mẹ bị bắn trúng => sinh thêm asteroid mẹ
                    Asteroid mom1(graphic->random(800, 1000), graphic->random(600, 800), graphic->random(0, 360), graphic->random(-100, 100), graphic->random(-100, 100), 2.0f);
                    vecAsteroid.push_back(mom1);
                }

                // xoá asteroid mẹ bị bắn trúng khỏi vector
                vecAsteroid.erase(vecAsteroid.begin() + j);

                // tăng điểm
                count += 10;

            }
        }
    }

    // thêm asteroid con vào vector asteroid ban đầu
    for (auto a : newAsteroid) {

        vecAsteroid.push_back(a);
        newAsteroid.pop_back(); // tránh tạo ra asteroid con liên tục

    }

    // nếu hết mạng -> thua
    if (lives <= 0) {

        dead = true;

    } 
}

// Hàm render màn hình chơi //
void PlayScreen::Render() {

    bg->Render(); // vẽ nền

    score->Render(); // vẽ điểm

    life->Render(); // vẽ mạng
            
    player->draw(graphic); // vẽ tàu

    for (int i = 0; i < vecAsteroid.size(); i++) { // vẽ asteroid
        vecAsteroid[i].draw(graphic);
    }
                
    for (int i = 0; i < vecBullet.size(); i++) { // vẽ bullet
        vecBullet[i].draw(graphic);
    }

    // nếu dead -> in lời nhắn cuối
    if (dead == true) {

        MissionFailed->Render();
        messageQuit->Render();
        dead = false;
    }
    
}

// Hàm check xem chết chưa //
bool PlayScreen::checkDead() {
    return dead;
}