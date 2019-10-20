#include "personnage.h"
#include "constante.h"



void personnage_jeu(SDL_Renderer* ecran ,int h, int w, int positionX , int positionY,  SDL_Texture* perso){

    SDL_Rect  position ;
    SDL_Rect* sprite = sprite_personnage();

 
    position.x = 0 ;
    position.y =  h - 5*(h/HAUTEUR_MAP);
    

    position.h = (h / HAUTEUR_MAP)*3 ;
    position.w = w / LARGEUR_MAP ;
    
    int err = SDL_RenderCopy(ecran, perso, &sprite[10], &position) ;
    printf("%d \n",err);
      
}

SDL_Rect* sprite_personnage(){
    SDL_Rect *sprite;
    sprite = malloc(sizeof(SDL_Rect)*NB_CASE_PERSO);

    int j = 0;
    for (int i = 0 ; i < NB_CASE_PERSO ; i++){ 
        //hauteur d'une case
        sprite[i].h = (HAUTEUR_SPRITE / NB_CASE_HAUTEUR) ; 
    
        //largeur d'une case
        sprite[i].w = LARGEUR_SPRITE / NB_CASE_LARGEUR ;

        //coordonnees x du sprite a afficher
        sprite[i].x = (i % NB_CASE_LARGEUR) * (sprite[i].w) ;
        if ((i % NB_CASE_LARGEUR == 0) && (i != 0)){
            
            j++ ;
        }
        
        //coordonnee y du sprite a afficher 
        sprite[i].y = j * (sprite[i].h) ;
          
        
    }
    
    return sprite ;

}