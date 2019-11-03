#include "structures.h"
#include "constante.h"

// structure commune à tous les personnages



// Fonctions d'écriture

// nouveau personnage

// écriture



// définition de base du raccoon

raccoon definir_raccoon(SDL_Renderer *ecran, raccoon r)
{

    raccoon r;

    r.vie = 200;

    r.image = charger_image_transparente("rocket_image.bmp", ecran, 0, 137, 84);

    r.sprite.x = 110 + 50;
    r.sprite.y = 142;
    r.sprite.w = LARGEUR_RACCOON;
    r.sprite.h = HAUTEUR_RACCOON;

    r.emplacement_sprite.x = 100;
    r.emplacement_sprite.y = 600;
    r.emplacement_sprite.w = 150;
    r.emplacement_sprite.h = 100;

    return r;
}

// Fonctions lecture

unsigned int lire_vie_raccoon(raccoon r)
{

    return r.vie;
}

int lire_abscisse_raccoon(raccoon r)
{

    return r.emplacement_sprite.x;
}

//lire emplacement...

/*
typedef struct Personnage chat1;
typedef struct Personnage chat2;
*/

/*
void afficher_raccoon(SDL_Renderer *ecran, SDL_Event evenements, raccoon r) /*, SDL_Rect sprite, SDL_Rect emplacement_raccoon)*/
/*{

    
    r.sprite = sprite_raccoon(evenements, r);

    // sprites de base

   

    // animation


    // avant : raccoon est ici une texture

    SDL_RenderCopy(ecran, r.image, &r.sprite, &r.emplacement_sprite);
}

*/

/*
SDL_Rect sprite_raccoon(SDL_Event evenements, raccoon r)
{

    //sprite = malloc(sizeof(SDL_Rect) * NB_CASE_PERSO);

    // animation

    //SDL_Event evenements;

    /*if (evenements.type == SDL_KEYDOWN)
    {*/
/*
    const Uint8 *etat_touche = SDL_GetKeyboardState(NULL);

    switch (evenements.type)
    {
    case SDL_KEYDOWN:
        switch (evenements.key.keysym.sym)
        {

        case SDLK_r:
            r.sprite.x += LARGEUR_RACCOON;
            //50;
            break;
        default:
            break;
        }
    }

    return r.sprite;
}
*/
/*void afficher_balle(SDL_Renderer *ecran, SDL_Texture *balle, bool afficher) /*, SDL_Rect sprite, SDL_Rect emplacement_raccoon)*/
//{

/* SDL_Rect position_balle;
    SDL_Rect image = sprite_raccoon();

    position_balle.x = 100;
    position_balle.y = 600;
    position_balle.w = 150;
    position_balle.h = 100;

    int temps_actuel = 0;
    int temps_precedent = 0;

    if (afficher == true)
    {

        while (position_balle.x < 1346)
        {

            // VITESSE_BALLE

            temps_actuel = SDL_GetTicks();

            while (position_balle.x < 1346 && temps_actuel - temps_precedent > 20)
            {

                /* if (activer_anim == true)
                printf("true\n");
            else
                printf("false\n");*/

/*   position_balle.x += VITESSE_BALLE;

                // printf("%d\n", sprite);

                temps_precedent = temps_actuel;
            }
            // afficher = false;

            SDL_RenderCopy(ecran, balle, &image, &position_balle);
        }
    }
}

SDL_Rect sprite_balle()
{
    SDL_Rect sprite;
    //sprite = malloc(sizeof(SDL_Rect) * NB_CASE_PERSO);

    sprite.x = 110;
    sprite.y = 142;
    sprite.w = LARGEUR_RACCOON;
    sprite.h = HAUTEUR_RACCOON;

    return sprite;
}*/
