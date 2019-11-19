#include "personnage.h"

void personnage_jeu(SDL_Renderer *ecran, int h, int w, int positionY, SDL_Texture *perso, int numSprite, SDL_Rect *sprite, int affichage_position_x)
{

    SDL_Rect position;
    //SDL_Rect* sprite = sprite_personnage();

    position.x = affichage_position_x * largeur_une_case(w);

    position.y = positionY * hauteur_une_case(h);

    position.h = (h / HAUTEUR_MAP) * 3;
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

void deplacement_sur_map(int *debutX, int direction, int *positionX, int *positionY, int *affichage_position_x)
{

    if (((direction > 0) && (*positionX < LARGEUR_TABLEAU - 1)) || (direction < 0 && *positionX > 0))
    {
        *positionX += direction;
    }
    if (*debutX + (direction) <= LARGEUR_TABLEAU - LARGEUR_MAP && *debutX + (direction) >= 0)
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
void saut(int *map, int direction, int vitesse, int *positionX, int *positionY, int h)
{

    int temps_precedent = 0;
    int temps_actuel = 0;

    int position_maximale = 40 + 4 * direction;
    //printf("position a atteindre %d\n", position_maximale);
    int ancienne_position = *positionY;

    //printf("position %d\n", ancienne_position);
    //printf("position a atteindre %d\n", position_maximale);

    if ((*positionY < HAUTEUR_MAP - 1) && (*positionY >= 0))//ne sort pas du tableau
    {
       while ((*positionY > position_maximale) && (!collision(map,direction, *positionX, *positionY)))
        {

            temps_actuel = SDL_GetTicks();

            // for (int i = 0; i < (5); i++)
            // {

            if (temps_actuel - temps_precedent > 200)
            {

                *positionY += direction;
                //printf("posY, %d\n", *positionY);

                //SDL_Delay(1000) ;
                temps_precedent = temps_actuel;
            }
            
            //gravite(map, direction, vitesse, positionX, positionY) ;
        }

        //a corriger while boucle infini 

/*
        //while (!collision(map,direction, *positionX, *positionY)){
            if (*positionY = position_maximale){  
                while ((*positionY < (*positionY + direction))&& (!sol)){
                    printf("coucou\n");
                    //gravite( vitesse, positionY) ;
                    gravite(map, vitesse, positionX, -1, positionY) ;
                }
            
            printf("posY, %d\n", *positionY);
        }
            if (*positionY = position_maximale){
            printf("coucou\n");

            //while ((!collision(map,direction, *positionX, *positionY))){
                //printf("bouh\n");
                gravite(map, vitesse, positionX, 1, positionY) ;
                //void gravite(int *map, int vitesse, int *positionX, int direction, int *positionY)
                printf("posY, %d\n", *positionY);
            //}
        }
        //}
        
        //temps_precedent = temps_actuel;
        // il redescend, 
        
        
        
        
        //pose problème

        while (*positionY < ancienne_position)
        {

            temps_actuel = SDL_GetTicks();

            // for (int i = 0; i < (5); i++)
            // {

            if (temps_actuel - temps_precedent > 50)
            {

                *positionY -= direction;
                //printf("%d, %d\n", *positionY, temps_actuel);

                //SDL_Delay(1000) ;
                temps_precedent = temps_actuel;
            }
            
        }*/
    }
}


void gravite(int *map, int vitesse, int *positionX, int direction, int *positionY){//(int* map, int direction, int vitesse, int *positionX, int *positionY
    while (!sol(map,direction, *positionX, *positionY)){

        *positionY += vitesse ;
    }
}


bool collision(int *map, int direction, int positionX, int positionY)
{

    //ajouter la colision au niveau de la tete
    bool condition1 = map[(positionX + direction) + positionY * LARGEUR_TABLEAU] == 2;       //position de x1 +1 == 2
    bool condition2 = map[(positionX + direction) + (positionY + 1) * LARGEUR_TABLEAU] == 2; // position de x2 +1 ==2
    bool condition3 = map[(positionX + direction) + (positionY + 2) * LARGEUR_TABLEAU] == 2; //position de x3 +1 == 2

    //colision avec le sol

   // bool condition4 = map[(positionX) + (positionY +2)*LARGEUR_TABLEAU + direction] == 3 ;  //les pied du perso touche le sol
    return condition1 || condition2 || condition3 ;// || condition4 ;
}

bool sol (int *map, int direction , int positionX, int positionY){
    bool condition = map[(positionX) + (positionY + 2)*LARGEUR_TABLEAU];
    return condition ;
}

// gerer lorsque le personnage atteint un trou
bool trou(int *map, int positionX, int positionY)
{
    return map[positionX + (positionY + 3) * LARGEUR_TABLEAU] == 1;
}
