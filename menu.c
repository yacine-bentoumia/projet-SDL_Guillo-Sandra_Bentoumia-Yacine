#include "menu.h"

void choix_menu(SDL_Renderer* ecran, SDL_Texture *tableau){
    
    SDL_RenderCopy(ecran, tableau, NULL, NULL);
}


void choix_option(SDL_Renderer* ecran,SDL_Texture* commande,SDL_Texture* fleche,SDL_Rect dest, int h, int w){
    dest.x = w -100 ;
    dest.y = h - 100 ;
    dest.h = 80 ;
    dest.w = 80 ;

    SDL_RenderCopy(ecran, commande, NULL, NULL);
    SDL_RenderCopy(ecran, fleche,NULL,&dest);
}

void choix_niveau(SDL_Renderer* ecran, SDL_Texture *tab_niv){
    SDL_RenderCopy(ecran, tab_niv, NULL, NULL);
}

   