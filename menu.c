#include "menu.h"

void choix_menu(SDL_Renderer* ecran, int num, SDL_Texture **tableau){
    
    SDL_RenderCopy(ecran, tableau[num], NULL, NULL);
}

   