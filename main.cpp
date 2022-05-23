/****************************************** NƠI TRÒ CHƠI DIỄN RA ******************************************/


#include "GameManager.h"


using namespace std;

/********************************* HÀM MAIN *********************************/
int main(int argc, char** argv){

    GameManager* game = GameManager::getInstance();

    game->Loop();
    
    GameManager::Release();
    game = NULL;

    return 0;
}