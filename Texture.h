/****************************************** THƯ VIỆN TEXTURE ******************************************/

#ifndef TEXTURE_H
#define TEXTURE_H

#include "AssetManager.h"


class Texture {

private:
    SDL_Texture* Tex;

    Graphics* tGraphic;

    SDL_Rect RenderRect;

public:
    Texture(string filename, int x, int y, int w, int h);
    Texture(string text, string font_path, int size, int x, int y, int w, int h);

    void changeCoords(int y);

    ~Texture();

    void Render(); 

};
#endif