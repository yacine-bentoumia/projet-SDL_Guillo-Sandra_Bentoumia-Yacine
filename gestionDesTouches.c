#include "gestionDesTouches.h"
#include "constante.h"
#include "personnage.h"

void gestionTouche(SDL_Event evenements, SDL_Renderer * ecran, bool* terminer,int *debutX,int *debutY, int *numSprite , int* positionX , int* positionY,int * affichage_position_x, int w){

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
                break ;
            case SDLK_RIGHT : // touche fleche droite
                
                deplacement_sur_map (debutX, 1 , positionX ,  positionY,affichage_position_x, w);

                    //printf("%d\n",*numSprite);
                    if ((*numSprite < 11)&&(*numSprite > 8)) {
                        //printf("coucou\n");
                        *numSprite += 1 ;
                    } 
                    else {
                        *numSprite = 9 ;
                    }
                
                break;
            case SDLK_LEFT : // touche fleche gauche
                deplacement_sur_map (debutX, (-1), positionX , positionY,affichage_position_x, w);
                   // printf("%d\n",*numSprite);
                   if ((*numSprite < 23) && (*numSprite > 20)){
                       *numSprite += 1 ;
                   }
                   else {
                       *numSprite = 21 ;
                   }
                

                break;
            
                
                
        }

        }

    
    
}