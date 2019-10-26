#include "personnage.h"
#include "constante.h"
#include "map.h"
#include "fenetreDuJeu.h"
#include "finDeJeu.h"



void personnage_jeu(SDL_Renderer* ecran ,int h, int w, int positionX , int positionY,  SDL_Texture* perso, int numSprite,SDL_Rect* sprite,int affichage_position_x){

    SDL_Rect  position ;
    //SDL_Rect* sprite = sprite_personnage();

    
    position.x = affichage_position_x*largeur_une_case(w);//positionX * largeur_une_case(w); ;
    //hauteur_case = ;
    position.y = positionY * hauteur_une_case(h) ;
    

    position.h = (h / HAUTEUR_MAP)*3 ;
    position.w = w / LARGEUR_MAP ;
    
    int err = SDL_RenderCopy(ecran, perso, &sprite[numSprite], &position) ;
    //printf("%d \n",err);
      
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

void deplacement_sur_map (int* debutX, int direction, int* positionX , int* positionY,int * affichage_position_x,int w){
    //printf("%d\n",*debutX);
    
    if(direction > 0 && *positionX<LARGEUR_TABLEAU-1 || direction < 0 && *positionX > 0 ){
        *positionX += direction ;
    }
    if(*debutX+(direction) <= LARGEUR_TABLEAU - LARGEUR_MAP && *debutX +(direction)>= 0){
        *debutX = *debutX+direction ;

        
    }else{

       
        if(*affichage_position_x < LARGEUR_MAP-1 && direction > 0 || direction < 0 && *affichage_position_x>0){
            *affichage_position_x +=direction;
           
        }
            
    }

    //printf("%d\n",*positionX);
    // rajouter la gestion de la position initial du perso
    //for (int i=0 ; i < LARGEUR_MAP ; i++){  //ne pas commencer a zero mais a la position x du perso
        //for (int j = 0 ; j < HAUTEUR_MAP ; j++){ //ne pas commencer a zero mais a la position y du perso -1 => pour avoir la case en dessous du perso
            /*if (map[i+1] == 0 && map[j+1] == 3){ 
                *numSprite +=1 ;
            }
            else if(map[i+1] == 0 && map[j+1] == 1){ // map[i+1] != 0
                *terminer = true; //il faudrait creer une animation en plus avec l'ajout de la graviter => plus tard
        }
         //gerer le fait que le personnage est sur Nb_case_perso donc    

*/
        

    
}

bool collision(int* map, int direction, int positionX, int positionY){
   
    //bool condition1 = direction == 1;
    bool condition1 = map[(positionX + direction) + positionY * LARGEUR_TABLEAU] == 2 ; //position de x1 +1 == 2
    bool condition2 = map[(positionX + direction) + (positionY + 1) * LARGEUR_TABLEAU] == 2 ; // position de x2 +1 ==2
    bool condition3 = map[(positionX + direction) + (positionY + 2) * LARGEUR_TABLEAU] == 2 ;//position de x3 +1 == 2
    return condition1 || condition2 || condition3 ;
}

//int champ = map[((i+debutX)+j*LARGEUR_TABLEAU) ]; 
