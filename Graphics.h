/****************************************** THƯ VIỆN ĐỒ HOẠ SDL2 ******************************************/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>

#define PI 3.14159265
#define DEG_TO_GRAD PI / 180.0f

using std::vector;
using std::pair;
using std::string;

class Graphics {

public:
    static const int SCREEN_WIDTH = 1000;
    static const int SCREEN_HEIGHT = 563;

private:
    static Graphics* Instance;
    static bool Initialized;


    SDL_Window *window; // cửa sổ
    SDL_Surface *BackBuffer; // bề mặt phụ ngoài màn hình
    SDL_Renderer *renderer; // kết xuất đồ hoạ


public:
    static Graphics* getInstance();
    static void Release();
    static bool isInitialized();
    SDL_Renderer *getRenderer();

    SDL_Texture* loadTexture(string path);
    SDL_Texture* CreateText(TTF_Font* font, std::string text);

    void drawTexture(SDL_Texture* tex, SDL_Rect* rendrect = NULL); 

    void ClearBackBuffer();

    void Render();

    void wrapCoordinates(float inputX, float inputY, float &outputX, float &outputY);
    void drawModel(Graphics *graphic, const vector<pair<float, float>> &ModelCoordinates, float x, float y, float angle, float scale);
    bool checkCollision(float x1, float y1, float x2, float y2, float radius);
    int random(int low, int high);

private:
    Graphics();
    ~Graphics();
    bool init();
};





#endif