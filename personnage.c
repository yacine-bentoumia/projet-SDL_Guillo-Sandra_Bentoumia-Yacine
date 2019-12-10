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

    if ((*positionY + (direction*vitesse) < map1.hauteur - 1) && (*positionY + (direction*vitesse) > 0))//ne sort pas du tableau 
    
    {         
        *positionY -= 1 * vitesse ;  
              

    }
}


void gravite( int direction, int *positionY, Carte map1){
   
       if ((*positionY + (direction) < map1.hauteur - 1) && (*positionY + (direction) > 0)){
           
            *positionY += direction ;//* vitesse ;

       }

    
}


bool collision(int direction, int positionX, int positionY, Carte map1)
{

   
    bool condition1 = map1.carteJeu[(positionX + direction) + positionY * map1.largeur] == '2';       //position de x1 +1 == 2
    bool condition2 = map1.carteJeu[(positionX + direction) + (positionY + 1) * map1.largeur] == '2'; // position de x2 +1 ==2
    bool condition3 = map1.carteJeu[(positionX + direction) + (positionY + 2) * map1.largeur] == '2'; //position de x3 +1 == 2


    // collision contre une tourelle

    bool condition4 = map1.carteJeu[(positionX + direction) + positionY * map1.largeur] == '4';       
    bool condition5 = map1.carteJeu[(positionX + direction) + (positionY + 1) * map1.largeur] == '4'; 
    bool condition6 = map1.carteJeu[(positionX + direction) + (positionY + 2) * map1.largeur] == '4'; 

    return condition1 || condition2 || condition3  || condition4 || condition5 || condition6;
}

bool collision_pied(int positionX, int positionY, Carte map1){
   

    bool condition_sol = map1.carteJeu[((positionX) + (positionY + 3)*map1.largeur)]== '3';
    bool condition_bloc = map1.carteJeu[((positionX) + (positionY + 3)*map1.largeur)]== '2' ;
    bool condition_gain = map1.carteJeu[((positionX) + (positionY + 3)*map1.largeur)]== '9';
   
    bool condition_tourelle = map1.carteJeu[((positionX) + (positionY + 3)*map1.largeur)]== '4';
        
    return (condition_sol || condition_bloc || condition_gain || condition_tourelle) ;
}

bool collision_tete(int positionX, int positionY, Carte map1){
    bool collision = false;
    
        for (int i= 0 ; i<15 ; i++){
        
            if (!collision){
                collision = map1.carteJeu[(positionX) + (positionY - i)*map1.largeur] == '2';
            }
       
        
        }
   
    return collision ;
}

// gerer lorsque le personnage atteint un trou
bool trou(int positionX, int positionY, Carte map1)
{
    return map1.carteJeu[positionX + (positionY + 3) * map1.largeur] == '1';
}

bool gagner(int positionX, int positionY, Carte map1){
    return map1.carteJeu[positionX + (positionY + 3) * map1.largeur] == '9' ;
}


int vie_du_personnage(){
    int vie = 3 ; 
    //sif (trou())
}









