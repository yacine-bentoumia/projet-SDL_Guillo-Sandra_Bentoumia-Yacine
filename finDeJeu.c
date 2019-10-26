#include "finDeJeu.h"


void gameOver(const char* nomfichier, SDL_Renderer* renderer){
    
    SDL_RenderClear(renderer);
    SDL_Texture* gameOver = charger_image (nomfichier, renderer) ;
    SDL_RenderCopy(renderer, gameOver, NULL, NULL) ;
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    
}

void win(const char* nomfichier, SDL_Renderer* renderer){
    SDL_RenderClear(renderer);
    SDL_Texture* win = charger_image (nomfichier, renderer) ;
    SDL_RenderCopy(renderer, win, NULL, NULL) ;
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);

}