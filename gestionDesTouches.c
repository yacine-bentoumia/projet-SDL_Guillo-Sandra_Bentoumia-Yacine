#include "gestionDesTouches.h"

void gestionTouche(SDL_Event evenements, SDL_Renderer * ecran, bool* terminer,int *debutX,  int *numSprite , int* positionX , int* positionY,int * affichage_position_x, int* map,int largeur,int hauteur, int* mode, int* num){

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
                    if(*mode == 0 ){
                        if(*num == 0){
                            *mode = 1;
                        }
                        else if(*num == 1 ){}
                        else if(*num == 2 ){}
                        else if(*num == 3 ){
                             *terminer = true ;
                        }
                    }else{
                    gameOver("gameOver.bmp", ecran);
                    *terminer = true ;
                    }
                    break;
                case SDLK_RIGHT : // touche fleche droite
                    if (!collision(map,1 ,*positionX, *positionY,largeur)){
                        deplacement_sur_map (debutX, 1 , positionX ,  affichage_position_x,largeur);
                    
                    }
                //SDL_Delay(1000);
                
                    if(trou(map, *positionX, *positionY, largeur)){
                    
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
                    if (!collision(map,-1 ,*positionX, *positionY,largeur)){
                        deplacement_sur_map (debutX, (-1), positionX ,affichage_position_x,largeur);
                    }
                    if(trou(map, *positionX, *positionY, largeur)){
                    
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
                    if (*mode == 0){
                        if (*num>0){
                            *num -=1 ;
                        }else if (*num == 0){
                            *num = 3;
                        }
                    }
                    if(!collision_tete(map, *positionX, *positionY,largeur)){
                        saut(-1 , 10, positionY, hauteur);
                    }
                    if(trou(map, *positionX, *positionY,largeur)){
                    
                        gameOver("gameOver.bmp", ecran);
                        *terminer = true ;
                    }
                    break ;
                case SDLK_DOWN : //fleche du bas
                //printf("c ouou\n");
                    if (*mode == 0){
                        if (*num<3){
                            *num +=1 ;
                        }else if (*num == 3){
                            *num = 0;
                        }
                        
                    }
         
                
                
        }

        }

    
    
}