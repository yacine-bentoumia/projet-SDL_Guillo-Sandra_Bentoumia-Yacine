#include "gestionDesTouches.h"

void gestionTouche(SDL_Event evenements, SDL_Renderer * ecran, bool* terminer,int *debutX,  int *numSprite , int* positionX , int* positionY,int * affichage_position_x, 
                                                     int* mode, int* num, int* numero, Carte map1,int * vitesse, int h , int w,SDL_Texture* perdu){
        SDL_Rect position ;
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
                case SDLK_RETURN  : //touche entrer
                    if(*mode == 0 ){
                        if(*num == 0){
                            
                            *mode = 1;
                        }
                        else if(*num == 1 ){
                            *mode = 2;
                        }
                        else if(*num == 2 ){
                            
                            *mode = 3 ;
                        }
                        else if(*num == 3 ){
                            *terminer = true ;
                        }
                    }else if(*mode == 3){
                        
                        *mode = 1 ;
                    }
                    break;
                case SDLK_RIGHT : // touche fleche droite
                    if (!collision(1 ,*positionX, *positionY,map1)){
                        deplacement_sur_map (debutX, 1 , positionX ,  affichage_position_x,map1);
                    
                    }

                    if ((*numSprite < 11)&&(*numSprite > 8)) {
                        *numSprite += 1 ;
                    } 
                    else {
                        *numSprite = 9 ;
                    }
                    break;
                case SDLK_LEFT : // touche fleche gauche
                    if (!collision(-1 ,*positionX, *positionY,map1)){
                        deplacement_sur_map (debutX, (-1), positionX ,affichage_position_x,map1);
                    }
                    if ((*numSprite < 23) && (*numSprite > 20)){
                        *numSprite += 1 ;
                    }
                    else {
                        *numSprite = 21 ;
                    }      
                    break;
                case SDLK_UP : //fleche du haut
                    if (*mode == 0){
                        if (*num>0){
                            *num -=1 ;
                        }else if (*num == 0){
                            *num = 3;
                        }
                    }else if(*mode == 3){
                        if (*numero>0){
                            *numero -=1 ;
                        }else if (*numero == 0){
                            *numero = 5;
                        }
                    }
                    *vitesse = 10 ;
                    collision_tete(*positionX, *positionY,map1,vitesse); 
                    saut(-1 ,*vitesse, positionY, map1);
                     
                    if(trou(*positionX, *positionY,map1)){
                        gameOver(ecran,perdu);
                        *terminer = true ;
                    }
                    break ;
                case SDLK_DOWN : //fleche du bas
                
                    if (*mode == 0){
                        if (*num<3){
                            *num +=1 ;
                        }else if (*num == 3){
                            *num = 0;
                        }
                        
                    }else if(*mode == 3){
                        if (*numero<5){
                            *numero +=1 ;
                        }else if (*numero == 5){
                            *numero = 0;
                        }
                    }

                    break ;
                }
        case SDL_MOUSEBUTTONUP:
                    switch(evenements.button.button){
                        case SDL_BUTTON_LEFT : //clique gauche souris 

                        position.x = evenements.button.x ;
                        position.y = evenements.button.y ;
                        if((position.x > (w-100) && position.x < (w-20))&&(position.y > (h-100) && position.y < (h-20))){
                       
                         *mode = 0 ;
                        }
                        break ;
                    }
                    break;
    }
}