#include "personnage.h"




void personnage_jeu(SDL_Renderer* ecran ,int h, int w , int positionY,  SDL_Texture* perso, int numSprite,SDL_Rect* sprite,int affichage_position_x){

    SDL_Rect  position ;
    //SDL_Rect* sprite = sprite_personnage();

    
    position.x = affichage_position_x*largeur_une_case(w);
   
    position.y = positionY * hauteur_une_case(h) ;
    

    position.h = (h / HAUTEUR_MAP)*3 ;
    position.w = w / LARGEUR_MAP ;
    
    SDL_RenderCopy(ecran, perso, &sprite[numSprite], &position) ;
    
      
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

void deplacement_sur_map (int* debutX, int direction, int* positionX , int* positionY,int * affichage_position_x){
    
    if(((direction > 0) && (*positionX<LARGEUR_TABLEAU-1)) || (direction < 0 && *positionX > 0 )){
        *positionX += direction ;
    }
    if(*debutX+(direction) <= LARGEUR_TABLEAU - LARGEUR_MAP && *debutX +(direction)>= 0){
        *debutX = *debutX+direction ;

        
    }else{

       
        if((*affichage_position_x < LARGEUR_MAP-1 && direction > 0) ||( direction < 0 && *affichage_position_x>0)){
            *affichage_position_x +=direction;
           
        }
            
    }       
}

//fonction du saut du personnage 
void saut (int direction, int* positionX, int* positionY, int h){
    
    int temp = *positionY;
   for (int i = 0 ; i < (5) ; i++){
        printf("%d\n", *positionY) ;

        if ((*positionY < HAUTEUR_MAP-1) && (*positionY >= 0)){
            *positionY += direction ;
            SDL_Delay(1000) ;
        }

   }
    
    
    
}




bool collision(int* map, int direction, int positionX, int positionY){
   
    //ajouter la colision au niveau de la tete 
    bool condition1 = map[(positionX + direction) + positionY * LARGEUR_TABLEAU] == 2 ; //position de x1 +1 == 2
    bool condition2 = map[(positionX + direction) + (positionY + 1) * LARGEUR_TABLEAU] == 2 ; // position de x2 +1 ==2
    bool condition3 = map[(positionX + direction) + (positionY + 2) * LARGEUR_TABLEAU] == 2 ;//position de x3 +1 == 2
    return condition1 || condition2 || condition3 ;
}

// gerer lorsque le personnage atteint un trou
bool trou(int* map, int positionX, int positionY){
   
    return map[positionX + (positionY + 3)* LARGEUR_TABLEAU] == 1 ;
}


