#include "AssetManager.h"

// Tạo ra một instance duy nhất, nếu đã có rồi thì trả về instance //
AssetManager* AssetManager::Instance = NULL;
AssetManager* AssetManager::getInstance() {
    if (Instance == NULL) Instance = new AssetManager();
    return Instance;
}

// Huỷ instance //
void AssetManager::Release() {
    delete Instance;
    Instance = NULL;
}

// Constructor //
AssetManager::AssetManager() {

}

// Destructor //
AssetManager::~AssetManager() {

    // huỷ các image đã đưa vào
    for (auto tex : Textures) {
        if (tex.second != NULL) {
            SDL_DestroyTexture(tex.second);
        }
    }

    Textures.clear();

    // huỷ các text đã đưa vào
    for (auto text : Text) {
        if (text.second != NULL) {
            SDL_DestroyTexture(text.second);
        }
    }

    Text.clear();

    // huỷ các font đã đưa vào
    for (auto font : Font) {
        if (font.second != NULL) {
            TTF_CloseFont(font.second);
        }

        Font.clear();
    }
}


// Hàm lấy hình ảnh từ file //
SDL_Texture* AssetManager::getTexture(std::string filename) {

    // lấy đường đến đến file chứa ảnh
    string fullpath = SDL_GetBasePath(); // lấy đường dẫn đến file
    fullpath.append("Image/" + filename);// thêm đường dẫn của thư mục chứa texture vào đường dẫn đến file

    // nếu ảnh chưa load thì load ảnh
    if (Textures[fullpath] == nullptr) {
        Textures[fullpath] = Graphics::getInstance()->loadTexture(fullpath); 
    } 

    //trả về ảnh đã load từ đường dẫn
    return Textures[fullpath];
}


// Hàm lấy font từ file //
TTF_Font* AssetManager::getFont(string filename, int size) {

    string fullpath_text = SDL_GetBasePath();
    fullpath_text.append("Font/" + filename);
    string key = fullpath_text + (char)size; // đường dẫn + kích cỡ chữ

    if (Font[key] == nullptr) {
        Font[key] = TTF_OpenFont(fullpath_text.c_str(), size);
        if (Font[key] == nullptr) {
            printf("Font Loading Error: Font-%s Error-%s", filename.c_str(), TTF_GetError());
        }
    }

    return Font[key];
}


// Hàm lấy text từ font //
SDL_Texture* AssetManager::getText(string text, string filename, int size) {
    TTF_Font* font = getFont(filename, size);
    string key = text + filename + (char)size;

    if(Text[key] == nullptr) {
        Text[key] = Graphics::getInstance()->CreateText(font, text);
    }

    return Text[key];
}

// Hàm lấy audio từ file //
Mix_Music* AssetManager::getAudio(string filename) {
    string fullpath_audio = SDL_GetBasePath();
    fullpath_audio.append("Audio/" + filename);

    if (Audio[fullpath_audio] == nullptr) {
        Audio[fullpath_audio] = Mix_LoadMUS(fullpath_audio.c_str());
        if (Audio[fullpath_audio] == NULL) {
            printf("Music Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
        }
    }

    return Audio[fullpath_audio];
}

// Hàm lấy SFX từ file //
Mix_Chunk* AssetManager::getSFX(string filename) {
    string fullpath_SFX = SDL_GetBasePath();
    fullpath_SFX.append("Audio/" + filename);

    if (SFX[fullpath_SFX] == nullptr) {
        SFX[fullpath_SFX] = Mix_LoadWAV(fullpath_SFX.c_str());
        if (SFX[fullpath_SFX] == NULL) {
            printf("SFX Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
        }
    }
    
    return SFX[fullpath_SFX];
}