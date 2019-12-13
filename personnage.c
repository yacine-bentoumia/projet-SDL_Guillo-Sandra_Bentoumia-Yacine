#include "personnage.h"

void personnage_jeu(SDL_Renderer *ecran, int h, int w, int positionY, SDL_Texture *perso, int numSprite, SDL_Rect *sprite, int affichage_position_x, Carte map1)
{

    SDL_Rect position;
    //SDL_Rect* sprite = sprite_personnage();

    position.x = affichage_position_x * largeur_une_case(w);

    position.y = positionY * hauteur_une_case(h,map1);

    position.h = (h / map1.hauteur) * 3;
    position.w = w / LARGEUR_MAP;


    SDL_RenderCopy(ecran, perso, &sprite[numSprite], &position);
}

SDL_Rect *sprite_personnage()
{
    SDL_Rect *sprite;
    sprite = malloc(sizeof(SDL_Rect) * NB_CASE_PERSO);

    int j = 0;
    for (int i = 0; i < NB_CASE_PERSO; i++)
    {
        //hauteur d'une case
        sprite[i].h = (HAUTEUR_SPRITE / NB_CASE_HAUTEUR);

        //largeur d'une case
        sprite[i].w = LARGEUR_SPRITE / NB_CASE_LARGEUR;

        //coordonnees x du sprite a afficher
        sprite[i].x = (i % NB_CASE_LARGEUR) * (sprite[i].w);
        if ((i % NB_CASE_LARGEUR == 0) && (i != 0))
        {

            j++;
        }

        //coordonnee y du sprite a afficher
        sprite[i].y = j * (sprite[i].h);
    }

    return sprite;
}

void deplacement_sur_map(int *debutX, int direction, int *positionX, int *affichage_position_x, Carte map1)
{

    if (((direction > 0) && (*positionX < map1.largeur - 1)) || (direction < 0 && *positionX > 0))
    {
        *positionX += direction;
    }
    if (*debutX + (direction) <= map1.largeur - LARGEUR_MAP && *debutX + (direction) >= 0)
    {
        *debutX = *debutX + direction;
    }
    else
    {

        if ((*affichage_position_x < LARGEUR_MAP - 1 && direction > 0) || (direction < 0 && *affichage_position_x > 0))
        {
            *affichage_position_x += direction;
        }
    }
}

//fonction du saut du personnage
void saut(int direction, int vitesse, int *positionY, Carte map1)
{ 

    if ((*positionY + (direction*vitesse) < map1.hauteur - 1) && (*positionY + (direction*vitesse) > 0))  {//ne sort pas du tableau 
    //int v = 0 ;
    //while (v!= vitesse){
        *positionY -= vitesse ;  
        
    //}            
              

    }
}


void gravite( int direction, int *positionY, Carte map1){
   
       if ((*positionY + (direction) < map1.hauteur - 1) && (*positionY + (direction) > 0)){
           
            *positionY += direction ;//* vitesse ;

       }

    
}


bool collision(int direction, int positionX, int positionY, Carte map1)
{

    // gestion de la collision sur la droite et la gauche du personnage 
    bool condition1 = map1.carteJeu[(positionX + direction) + positionY * map1.largeur] == '2';       //position de x1 +1 == 2
    bool condition2 = map1.carteJeu[(positionX + direction) + (positionY + 1) * map1.largeur] == '2'; // position de x2 +1 ==2
    bool condition3 = map1.carteJeu[(positionX + direction) + (positionY + 2) * map1.largeur] == '2'; //position de x3 +1 == 2


    // collision contre une tourelle

    bool condition4 = map1.carteJeu[(positionX + direction) + positionY * map1.largeur] == '4';       
    bool condition5 = map1.carteJeu[(positionX + direction) + (positionY + 1) * map1.largeur] == '4'; 
    bool condition6 = map1.carteJeu[(positionX + direction) + (positionY + 2) * map1.largeur] == '4'; 

    bool condition7 = map1.carteJeu[(positionX + direction) + positionY * map1.largeur] == '5';       
    bool condition8 = map1.carteJeu[(positionX + direction) + (positionY + 1) * map1.largeur] == '5'; 
    bool condition9 = map1.carteJeu[(positionX + direction) + (positionY + 2) * map1.largeur] == '5'; 

    //bool condition7 = map1.carteJeu[(positionX + direction) + (positionY - 1) * map1.largeur] == '8' ;

    return condition1 || condition2 || condition3  || condition4 || condition5 || condition6 || condition7 || condition8 || condition9 ;
}

bool collision_pied(int positionX, int positionY, Carte map1){
   

    bool condition_sol = map1.carteJeu[((positionX) + (positionY + 3)*map1.largeur)]== '3' ;
    bool condition_bloc = map1.carteJeu[((positionX) + (positionY + 3)*map1.largeur)]== '2' ;
    bool condition_gain = map1.carteJeu[((positionX) + (positionY + 3)*map1.largeur)]== '9';
   
    bool condition_tourelle = map1.carteJeu[((positionX) + (positionY + 3)*map1.largeur)]== '4';
        
    return (condition_sol || condition_bloc || condition_gain || condition_tourelle) ;
}

void collision_tete(int positionX, int positionY, Carte map1,int* vitesse){
    
    bool collision  ;
    bool condition ;
    bool condition2;

    int i;
    
        for (i = 1 ; i < (*vitesse) && (!collision) && (!condition) && (!condition2); i++){ // && (!collision)
            collision = map1.carteJeu[(positionX) + (positionY - i)*map1.largeur] == '2';   
            condition = map1.carteJeu[(positionX) + (positionY - i) * map1.largeur] == '8' ;  
            condition2 =  map1.carteJeu[(positionX) + (positionY - i) * map1.largeur] == '4' ;  

        }
        *vitesse = i - 2;
        
   
}
bool perte_de_vie(int positionX,int positionY,Carte map1){
    //si le personnage touche des pics avec les pieds
    bool condition =  map1.carteJeu[((positionX) + (positionY + 3)*map1.largeur)]== 'p';
    //si le personnage touche des pics avec le corps
    bool condition1 = map1.carteJeu[(positionX) + positionY * map1.largeur] == 'p';       //position de x1 +1 == 2
    bool condition2 = map1.carteJeu[(positionX) + (positionY + 1) * map1.largeur] == 'p'; // position de x2 +1 ==2
    bool condition3 = map1.carteJeu[(positionX) + (positionY + 2) * map1.largeur] == 'p';
    //si le perso touche des pics avec la tete 
    bool condition4 = map1.carteJeu[(positionX) + (positionY - 1)*map1.largeur] == 'p';
    return condition || condition1 || condition2 || condition3 || condition4 ;
}

// gerer lorsque le personnage atteint un trou
bool trou(int positionX, int positionY, Carte map1)
{
    return map1.carteJeu[positionX + (positionY + 3) * map1.largeur] == '1';
}

bool gagner(int positionX, int positionY, Carte map1){
    return map1.carteJeu[positionX + (positionY + 3) * map1.largeur] == '9' ;
}


void vie_du_personnage(SDL_Renderer *ecran,SDL_Texture *vie,int vie_perso){
    
    SDL_Rect  pos ;
    //position
    pos.x = 10 ;
    pos.y = 10 ;
    //taille
    pos.h = 50 ;
    pos.w = 50 ;

   
        for (int i = 0 ; i < vie_perso ; i++){
            SDL_RenderCopy(ecran,vie, NULL, &pos);
                //printf("%d \n",pos.x);
                pos.x += 50 ;
        }
            
            
}

void nb_vie_perso(int positionX,int positionY,Carte map1,int* nb_vie,int *posX,int *posY){
    
    if (*posX != positionX && *posY != positionY && perte_de_vie(positionX,positionY,map1)){
        *nb_vie -= 1 ;
        *posX = positionX ;
        *posY = positionY ;
    }
}
