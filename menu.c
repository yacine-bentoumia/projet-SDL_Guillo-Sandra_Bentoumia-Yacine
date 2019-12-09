#include "menu.h"

void choix_menu(SDL_Renderer* ecran, SDL_Texture *tableau){
    
    SDL_RenderCopy(ecran, tableau, NULL, NULL);
}


void choix_option(SDL_Renderer* ecran,SDL_Texture* commande){
    SDL_RenderCopy(ecran, commande, NULL, NULL);
}

void choix_niveau(SDL_Renderer* ecran, SDL_Texture *tab_niv){
    SDL_RenderCopy(ecran, tab_niv, NULL, NULL);
}

   