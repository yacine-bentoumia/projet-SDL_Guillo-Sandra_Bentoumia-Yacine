#include "difficultes.h"


int nb_de_balle(Carte map1){
    //compte le nombre de tours presente dans la carte map1
    int compteur = 0 ;
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

void copie_de_position(SDL_Rect*posBalle,SDL_Rect*dep_balle,int taille){
    for (int i = 0 ; i < taille ; i ++){
        dep_balle[i].x = posBalle[i].x ;
        dep_balle[i].y = posBalle[i].y ;
        dep_balle[i].h = posBalle[i].h ;
        dep_balle[i].w = posBalle[i].w ;
    }
  
}

void deplacer_balle(SDL_Rect* pos_tab,int w,int taille){
    int largeur = largeur_une_case(w) ;
    for (int i = 0; i < taille ; i++){
        pos_tab[i].x -= largeur ;
    }


}