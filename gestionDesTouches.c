#include "gestionDesTouches.h"
#include "constante.h"

void gestionTouche(SDL_Event evenements, SDL_Renderer * ecran, bool* terminer){
    
        switch(evenements.type)
        {
            case SDL_QUIT:
                *terminer = true; 
            break;
        case SDL_KEYDOWN:
        switch(evenements.key.keysym.sym)
        {
            case SDLK_ESCAPE: //touche echappe
            case SDLK_q:
                *terminer = true; 
                break;
            //test de l'affichage du game over avec la touche entrer
            case SDLK_RETURN  : //touche entrer
                gameOver("gameOver.bmp", ecran);
                *terminer = true ;
                break;
            //test affichage du winner avec la touche espace
            case SDLK_SPACE : //touche barre d'espace
                win("winner.bmp", ecran);
                *terminer = true ;
        }       break ;

        }

    
    
}