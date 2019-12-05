#include "gestionDesTouches.h"

void gestionTouche(SDL_Event evenements, SDL_Renderer * ecran, bool* terminer,int *debutX,  int *numSprite , int* positionX , int* positionY,int * affichage_position_x, int* map){

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
            case SDLK_RIGHT : // touche fleche droite
                if (!collision(map,1 ,*positionX, *positionY)){
                    deplacement_sur_map (debutX, 1 , positionX ,  affichage_position_x);
                    
                }
                //SDL_Delay(1000);
                
                if(trou(map, *positionX, *positionY)){
                    
                    gameOver("gameOver.bmp", ecran);
                    *terminer = true ;
                }

                if ((*numSprite < 11)&&(*numSprite > 8)) {
                    *numSprite += 1 ;
                } 
                else {
                    *numSprite = 9 ;
                }
                break;
            case SDLK_LEFT : // touche fleche gauche
                if (!collision(map,-1 ,*positionX, *positionY)){
                    deplacement_sur_map (debutX, (-1), positionX ,affichage_position_x);
                }
                if(trou(map, *positionX, *positionY)){
                    
                    gameOver("gameOver.bmp", ecran);
                    *terminer = true ;
                }
                   
                if ((*numSprite < 23) && (*numSprite > 20)){
                    *numSprite += 1 ;
                }
                else {
                    *numSprite = 21 ;
                }      
                break;
            case SDLK_UP : //fleche du haut
            if (!collision_tete(map, *positionX, *positionY)){
                saut(-1 , 10, positionY);
            }
            if(trou(map, *positionX, *positionY)){
                    
                gameOver("gameOver.bmp", ecran);
                *terminer = true ;
            }
                
            
                    
                break ;
         
                
                
        }

        }

    
    
}