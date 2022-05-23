#include "Texture.h"

// Constructor cho ảnh PNG //
Texture::Texture(string filename, int x, int y, int w, int h) {
    tGraphic = Graphics::getInstance();

    Tex = AssetManager::getInstance()->getTexture(filename);

    RenderRect.w = w;
    RenderRect.h = h;
    RenderRect.x = (int)(x - w/2); // đưa tâm ảnh về tâm hình chữ nhật
    RenderRect.y = y;
}

// Constructor cho text //
Texture::Texture(string text, string font_path, int size, int x, int y, int w, int h) {
    tGraphic = Graphics::getInstance();

    Tex = AssetManager::getInstance()->getText(text, font_path, size);

    RenderRect.w = w;
    RenderRect.h = h;
    RenderRect.x = (int)(x - w/2);
    RenderRect.y = y;
}

// Destructor //
Texture::~Texture() {   
    Tex = NULL;
    tGraphic = NULL;
}

void Texture::changeCoords(int y) {
    RenderRect.y = y;
}

// Hàm render //
void Texture::Render() {
    tGraphic->drawTexture(Tex, &RenderRect);
}