/****************************************** THƯ VIỆN XỬ LÍ CÁC TÀI NGUYÊN CỦA GAME ******************************************/

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "Graphics.h"

class AssetManager {

private:

    static AssetManager* Instance;

    std::map<string, SDL_Texture*> Textures;

    std::map<string, SDL_Texture*> Text;
    std::map<string, TTF_Font*> Font;

    std::map<string, Mix_Music*> Audio;
    std::map<string, Mix_Chunk*> SFX;

public:

    static AssetManager* getInstance();
    static void Release();

    SDL_Texture* getTexture(string filename);

    SDL_Texture* getText(string text, string filename, int size);
    
    Mix_Music* getAudio(string filename);
    Mix_Chunk* getSFX(string filename);

private:

    AssetManager();
    ~AssetManager();
    TTF_Font* getFont(string filename, int size);
    
};

#endif
