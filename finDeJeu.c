#include "finDeJeu.h"

void gameOver(const char* nomfichier, SDL_Renderer* renderer){
    
    SDL_RenderClear(renderer);
    SDL_Texture* gameOver = charger_image (nomfichier, renderer) ;
    SDL_RenderCopy(renderer, gameOver, NULL, NULL) ;
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    
}