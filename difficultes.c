#include "difficultes.h"


int def_position_balle(Carte map1){
    //compte le nombre de tours presente dans la carte map1
    int compteur = 0 ;
    //SDL_Rect* tab ;
    for (int i = 0 ; i < map1.taille ; i++){
        if (map1.carteJeu[i] == '5' ){
            compteur++ ;
        }
    }
    return compteur;
    
}



void affichage_balle(SDL_Renderer* ecran,SDL_Texture* balle,SDL_Rect* posBalle,int taille){
    for (int i = 0 ; i < taille ; i ++){

        SDL_RenderCopy(ecran, balle, NULL, &posBalle[i]) ;
    }
    
}