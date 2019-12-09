#include "gestionDesTouches.h"

void gestionTouche(SDL_Event evenements, SDL_Renderer * ecran, bool* terminer,int *debutX,  int *numSprite , int* positionX , int* positionY,int * affichage_position_x, 
                                                    int* map,int largeur,int hauteur, int* mode, int* num, int* numero){
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
            //test de l'affichage du game over avec la touche entrer
                case SDLK_RETURN  : //touche entrer
                    if(*mode == 0 ){
                        if(*num == 0){
                            //free(*map);
                            //*map = lire_fichier("map2.txt",&hauteur, &largeur, &taille);
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
                    if(trou(map, *positionX, *positionY,largeur)){
                    
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
                    }else if(*mode == 3){
                        if (*numero>0){
                            *numero -=1 ;
                        }else if (*numero == 0){
                            *numero = 5;
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
                 //printf("coucou : %d : %d \n",evenements.button.x, evenements.button.y);
                    switch(evenements.button.button){
                        case SDL_BUTTON_LEFT : //clique souris 

                        position.x = evenements.button.x ;
                        position.y = evenements.button.y ;
                        
                        if((position.x > 1225 && position.x < 1260)&&(position.y < 870 && position.y > 820)){
                         //printf("x %d : y %d \n",evenements.button.x, evenements.button.y);   
                         *mode = 0 ;
                        }
                        break ;
                    }
                    
                    break;

        }

    
    
}