#include "difficultes.h"

//compte le nombre de tours qui tire les balles presentent dans la carte map1 ainsi que le nombre de tours qui tirent des missiles
void nb_de_balle(Carte map1,int* cmp_balle,int* cmp_missile){
    for (int i = 0 ; i < map1.taille ; i++){
        //compte le nombre de tours qui tire les balles
        if (map1.carteJeu[i] == '5' ){
            *cmp_balle += 1 ;
        //compte le nombre de tours qui tire les missiles presentent dans la carte map1
        }else if(map1.carteJeu[i] == '8'){
            *cmp_missile += 1 ;
        }
    }
    
}
//fonction qui gere l'affichage des balles (et des missiles)
void affichage_balle(SDL_Renderer* ecran,SDL_Texture* balle,SDL_Rect* posBalle,int taille){
    for (int i = 0 ; i < taille ; i ++){
        SDL_RenderCopy(ecran, balle, NULL, &posBalle[i]) ;
    }
}

//fonction qui fait une copie des tableau pour pouvoir modifier les valeur pour le deplacement 
void copie_de_position(SDL_Rect*posBalle,SDL_Rect*dep_balle,int taille){
    for (int i = 0 ; i < taille ; i ++){
        dep_balle[i].x = posBalle[i].x ;
        dep_balle[i].y = posBalle[i].y ;
        dep_balle[i].h = posBalle[i].h ;
        dep_balle[i].w = posBalle[i].w ;
    }
  
}
//fonction de deplacement des balles
void deplacer_balle(SDL_Rect* pos_tab,int w,int taille){
    int largeur = largeur_une_case(w) ;
    for (int i = 0; i < taille ; i++){
        pos_tab[i].x -= largeur ;
    }
}
//fonction de deplacement des missiles
void deplacer_missile(SDL_Rect* pos_tab,int taille,SDL_Rect* tab){

    for (int i = 0; i < taille ; i++){
        pos_tab[i].x = tab[i].x ;
        pos_tab[i].h = tab[i].h ;
        pos_tab[i].w = tab[i].w ;
        pos_tab[i].y += 10;
    }


}