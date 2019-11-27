#include "ennemis.h"

// tourelle 1

/*void tourelle(SDL_Renderer *ecran, int h, int w, int positionY, SDL_Texture *perso, int numSprite, SDL_Rect sprite, int affichage_position_x)
{

    SDL_Rect position;
    //SDL_Rect* sprite = sprite_personnage();

    position.x = affichage_position_x * 52;//largeur_une_case(w); //312
    //printf("haut_case %d\n", hauteur_une_case(h));

    position.y = positionY * hauteur_une_case(h) + 15; //575

    // printf("posX, posY = (%d, %d)\n", position.x, position.y);

    position.h = HAUTEUR_MAP - 13;    //32
    position.w = 2 * LARGEUR_MAP + 4; //54

    SDL_RenderCopy(ecran, perso, &sprite, &position);
}

SDL_Rect sprite_tourelle()
{
    SDL_Rect sprite;
    //sprite = malloc(sizeof(SDL_Rect) * NB_CASE_TOURELLE);

    //32 54 14 139

    /*for (int i = 0; i < NB_CASE_TOURELLE + 1; i++)
    {*/

/*  //hauteur d'une case
        sprite.h = 30;

        //largeur d'une case
        sprite.w = 52;

        //coordonnees x du sprite a afficher
        sprite.x = 15;

        //coordonnee y du sprite a afficher
        sprite.y = 140;
   // }

    return sprite;
}*/

// scientifique

void stf(SDL_Renderer *ecran, SDL_Texture *perso, SDL_Rect *sprite, int numSprite)
{

    SDL_Rect position;

    position.x = 300;

    position.y = 250;

    position.h = 50;
    position.w = 50;

    SDL_RenderCopy(ecran, perso, &sprite[numSprite], &position);
}

SDL_Rect *sprite_stf()
{
    SDL_Rect *sprite;
    sprite = malloc(sizeof(SDL_Rect) * NB_SPRITE_STF);

    int j = 0;
    for (int i = 0; i < NB_SPRITE_STF; i++)
    {
        //hauteur d'une case
        sprite[i].h = 45;

        //largeur d'une case
        sprite[i].w = LARGEUR_STF;

        //coordonnees x du sprite a afficher
        sprite[i].x = i * 135;

        //coordonnee y du sprite a afficher
        sprite[i].y = 4;
    }

    return sprite;
}

/*void deplacement_stf(int *debutX, int direction, int *positionX, int *positionY, int *affichage_position_x)
{

    int temps_actuel = 0;
    int temps_precedent = 0;

    temps_actuel = SDL_GetTicks();

    while (temps_actuel - temps_precedent > 1)
    {

        if (*positionX > 0)
        {

            *positionX -= direction;
            //temps_precedent = temps_actuel;
        }

        else
        {

            *positionX = 200;
            //temps_precedent = temps_actuel;
        }

        temps_precedent = temps_actuel;
    }
}*/

SDL_Rect sprite_balle1()
{
    SDL_Rect sprite;

    //hauteur d'une case
    sprite.h = 7;

    //largeur d'une case
    sprite.w = 16;

    //coordonnees x du sprite a afficher
    sprite.x = 0;

    //coordonnee y du sprite a afficher
    sprite.y = 0;

    return sprite;
}

void emplacement_balle1(SDL_Renderer *ecran, SDL_Texture *perso, SDL_Rect sprite, int *map)
{

    SDL_Rect position;

    position.x = 298;

    position.y = 588;

    position.h = 7;

    position.w = 16;

    int temps_actuel = 0;
    int temps_precedent = 0;

    bool activer = true;

    while (activer)
    {

        temps_actuel = SDL_GetTicks();

        while (temps_actuel - temps_precedent > 1000)
        {
            //SDL_RenderCopy(ecran, perso, &sprite, &position);
            if (position.x > -sprite.w)
            {

                position.x -= 2;
            }

            else
            {

                position.x = 298;
            }
            printf("posx: %d\n", position.x);
            temps_precedent = temps_actuel;
        }
    }
}