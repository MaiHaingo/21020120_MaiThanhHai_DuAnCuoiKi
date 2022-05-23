#include "Graphics.h"

// Tạo ra một instance duy nhất, nếu đã có rồi thì trả về instance //
Graphics* Graphics::Instance = NULL;
bool Graphics::Initialized = false;

Graphics* Graphics::getInstance() {

    if (Instance == NULL) Instance = new Graphics();
    return Instance;

}


// Huỷ instance //
void Graphics::Release() {

    delete Instance;
    Instance = NULL;
    Initialized = false;

}

// Hàm kiểm tra đồ hoạ đã được khởi tạo chưa //
bool Graphics::isInitialized() {

    return Initialized;

}

// Constructor //
Graphics::Graphics() {

    BackBuffer = NULL;
    Initialized = init();

}

// Destructor //
Graphics::~Graphics() {

    SDL_DestroyWindow(window);
    window = NULL;
    
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

}

// Hàm khởi tạo đồ hoạ //
bool Graphics::init() { 

    // khởi tạo SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 ) {

        printf("SDL Initialization Error: %s\n", SDL_GetError());
        return false;

    }

    // khởi tạo cửa sổ
    window = SDL_CreateWindow("VoyagerX", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {

        printf("Window Creation Error: %s\n", SDL_GetError());
        return false;

    }

    // khởi tạo render
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {

        printf("Renderer Creation Error: %s\n", SDL_GetError());

    }

    // set color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);    
    
    // khởi tạo SDL_image (ảnh PNG)
    int flags = IMG_INIT_PNG;
    if (!(IMG_Init(flags) & flags)){

        printf("IMG Initialization Error: %s\n", IMG_GetError());
        return false;

    }

    // khởi tạo SDL_ttf
    if (TTF_Init() == -1) {

        printf("TTF Initialization Error: %s\n", TTF_GetError());
        return false;

    }

    BackBuffer = SDL_GetWindowSurface(window);

    return true;

}

// Hàm load texture //
SDL_Texture* Graphics::loadTexture(string path) {

    // khởi tạo con trỏ texture và đặt bằng NULL
    SDL_Texture* tex = NULL; 

    // load ảnh từ file
    SDL_Surface* surface = IMG_Load(path.c_str()); 

    if (surface == NULL) {
        printf("Image Load Error: Path(%s) - Error(%s)\n", path.c_str(), IMG_GetError());
        return tex;
    }

    // tạo texture từ surface
    tex = SDL_CreateTextureFromSurface(renderer, surface); 

    if (tex == NULL) {
        printf("Create Texture Error: %s\n", SDL_GetError());
        return tex;
    }

    // giải phóng surface
    SDL_FreeSurface(surface);

    // trả về texture
    return tex;
}

// Hàm tạo text //
SDL_Texture* Graphics::CreateText(TTF_Font* font, std::string text) {

    // tạo ra text với font, xâu cần chuyển thành text và màu
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), {255, 255, 255}); 
    if (surface == NULL) {
        printf("Text Render Error: %s\n", TTF_GetError());
        return NULL;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
    if (tex == NULL) {
        printf("Text Creation Error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_FreeSurface(surface);

    return tex;
}

// Hàm vẽ texture bằng cách render một hình chữ nhật từ source texture //
void Graphics::drawTexture(SDL_Texture* tex, SDL_Rect* rendrect) {
    SDL_RenderCopy(renderer, tex, NULL, rendrect);
}

// Hàm clear màn hình bằng màu đen //
void Graphics::ClearBackBuffer() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

// Hàm render lên màn hình //
void Graphics::Render() {
    SDL_RenderPresent(renderer);
}

// Hàm lấy renderer //
SDL_Renderer* Graphics::getRenderer() {
    return renderer;
}

// Hàm wrap toạ độ //
void Graphics::wrapCoordinates(float inputX, float inputY, float &outputX, float &outputY) {
    outputX = inputX;
    outputY = inputY;

    if (inputX < 0.0f) outputX = inputX + (float) SCREEN_WIDTH; // nếu vật đi quá lề trái của screen => xuất hiện ở lề phải
    if (inputX >= (float) SCREEN_WIDTH) outputX = inputX - (float) SCREEN_WIDTH; // ngược lại

    if (inputY < 0.0f) outputY = inputY + (float) SCREEN_HEIGHT; // nếu vật đi quá lề trên của screen => xuất hiện ở lề dưới
    if (inputY >= (float) SCREEN_HEIGHT) outputY = inputY - (float) SCREEN_HEIGHT; // ngược lại

}

// Hàm vẽ mô hình từ một tập các điểm trong không gian //
void Graphics::drawModel(Graphics *graphic, const vector<pair<float, float>> &ModelCoordinates, float x, float y, float angle, float scale) {

    vector<pair<float, float>> TransformedCoordinates; // vector lưu toạ độ sau khi đổi
    int verts = ModelCoordinates.size();  // độ dài của vector lưu bằng độ dài vector ban đầu (cũng là số đỉnh của model)
    TransformedCoordinates.resize(verts); // đổi lại size của vector lưu

    // xoay toạ độ
    for (int i = 0; i < verts; i++) {
        TransformedCoordinates[i].first = ModelCoordinates[i].first * cos(angle) - ModelCoordinates[i].second * sin(angle);
        TransformedCoordinates[i].second = ModelCoordinates[i].first * sin(angle) + ModelCoordinates[i].second * cos(angle);
    }

    // scale model
    for (int i = 0; i < verts; i++) {
        TransformedCoordinates[i].first = TransformedCoordinates[i].first * scale;
        TransformedCoordinates[i].second = TransformedCoordinates[i].second * scale;
    }

    // tịnh tiến toạ độ lên vị trí toạ độ của tâm model
    for (int i = 0; i < verts; i++) {
        TransformedCoordinates[i].first = TransformedCoordinates[i].first + x;
        TransformedCoordinates[i].second = TransformedCoordinates[i].second + y;
    }

    // vẽ
    for (int i = 0; i < verts; i++) {
        int j = (i + 1);
        SDL_RenderDrawLine(graphic->getRenderer(),TransformedCoordinates[i % verts].first, TransformedCoordinates[i % verts].second, TransformedCoordinates[j % verts].first, TransformedCoordinates[j % verts].second); 
    }
}

// Hàm check va chạm //
bool Graphics::checkCollision(float x1, float y1, float x2, float y2, float radius) {
    if (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < radius) return true;
    else return false;
}

int Graphics::random(int low, int high) {
    return low + rand() % (high + 1 - low);
}