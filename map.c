#include "map.h"



SDL_Rect dest , pos ;

void carteDuJeu (SDL_Renderer* ecran, SDL_Texture* sol,SDL_Texture* ciel , SDL_Texture* obstacle ,SDL_Texture* trou, SDL_Texture* tour4, SDL_Texture* tour5, 
SDL_Texture* tour6, SDL_Texture* tour7, SDL_Texture* tour8,int w, int h,int debutX,SDL_Texture* gain, Carte map1){

    dest.x = 0 ;
    dest.y = 0 ;


    //hauteur d'une case
    int hauteur_case = hauteur_une_case(h,map1) ;
    //largeur d'une case
    int largeur_case = largeur_une_case(w) ;

    
    pos.h = hauteur_case ;
    pos.w = largeur_case ;
    
    
 
    for (int i = 0 ; i < LARGEUR_MAP ; i++){ 
       
        for (int j = 0 ; j < map1.hauteur ; j++) {
           
            //position initiale
            pos.x = (i * largeur_case) ;
            pos.y = (j * hauteur_case) ;
            char champ = map1.carteJeu[((i+debutX)+j*map1.largeur) ]; 
          
            switch(champ) 
            {
                case '0' :
                SDL_RenderCopy(ecran, ciel, &dest, &pos) ;
                break ;
                case '1' :
                SDL_RenderCopy(ecran, obstacle, &dest, &pos) ;
                break ;
                case '2' :
                SDL_RenderCopy(ecran, trou, &dest, &pos) ;
                break ;
                case '3' :
                SDL_RenderCopy(ecran, sol, &dest, &pos) ;
                break ;
                case '4':
                SDL_RenderCopy(ecran, tour4, &dest, &pos);
                break;
                case '5':
                SDL_RenderCopy(ecran, tour5, &dest, &pos);
                break;
                case '6':
                SDL_RenderCopy(ecran, tour6, &dest, &pos);
                break;
                case '7':
                SDL_RenderCopy(ecran, tour7, &dest, &pos);
                break;
                case '8':
                SDL_RenderCopy(ecran, tour8, &dest, &pos);
                break;
                case '9' :
                SDL_RenderCopy(ecran, gain, &dest, &pos);
                
                
                break;
                default : 
                SDL_RenderCopy(ecran, ciel, &dest, &pos) ;
                break;
                
            }
        }
    }



}


int hauteur_une_case(int h, Carte map1){
    

    //hauteur d'une case
    if(h % map1.hauteur==0){
        dest.h = (h / map1.hauteur) ; // h = hauteur_fenetre
    }
    else{
        dest.h = (h / map1.hauteur) + 1;
    }
    return dest.h ;
}

int largeur_une_case(int w){

    //largeur d'une case
    if(w % LARGEUR_MAP==0){
        dest.w = w / LARGEUR_MAP ; // w = largeur_fenetre
    }
    else{
        dest.w = (w / LARGEUR_MAP) + 1 ;
    }
    return dest.w ;
}
 
