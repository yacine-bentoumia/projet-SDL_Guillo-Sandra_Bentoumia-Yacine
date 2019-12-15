#include "finDeJeu.h"


void gameOver(SDL_Renderer* renderer, SDL_Texture* gameOver){
    
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, gameOver, NULL, NULL) ;
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    
}

void win(SDL_Renderer* renderer,SDL_Texture* win){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, win, NULL, NULL) ;
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);

}