#include "finDeJeu.h"

//fonction qui appelle l'affichage de l'image perdu quand on a gameOver
void gameOver(SDL_Renderer* renderer, SDL_Texture* gameOver){
    
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, gameOver, NULL, NULL) ;
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    
}
//fonction qui appelle l'affichage de l'image winner quand on a gagné
void win(SDL_Renderer* renderer,SDL_Texture* win){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, win, NULL, NULL) ;
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);

}