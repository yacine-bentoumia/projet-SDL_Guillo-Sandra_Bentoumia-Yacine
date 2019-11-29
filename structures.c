#include "structures.h"
#include "constante.h"

// Fonctions d'écriture

// nouveau personnage

// écriture

// définition de base du ennemi

/*ennemi definir(SDL_Renderer *ecran, ennemi e)
{

    ennemi e;

    e.vie = 200;

    e.image = charger_image_transparente("scientifique.bmp", ecran, 255, 0, 0);

    e.sprite.x = 110 + 50;
    e.sprite.y = 142;
    e.sprite.w = TAILLE_STF;
    e.sprite.h = TAILLE_STF;

    e.emplacement_sprite.x = 100;
    e.emplacement_sprite.y = 600;
    e.emplacement_sprite.w = 150;
    e.emplacement_sprite.h = 100;

    return e;
}*/

ennemi definir_nouveau_personnage(SDL_Renderer *ecran)
{

    ennemi e;

    e.vie = 0;
    e.vitesse = 0;
    //e.nom = "";
    e.image = NULL;
    /*e.sprite = NULL;
    e.emplacement_sprite = NULL;*/

    return e;
}

// fonctions d'écriture

ennemi definir_vie(ennemi e, unsigned int vie)
{

    e.vie = vie;

    return e;
}

ennemi definir_vitesse(ennemi e, int vitesse)
{

    e.vitesse = vitesse;

    return e;
}

ennemi definir_nom(ennemi e, char *nom)
{

    for (int i = 0; i < 20; i++)
    {

        e.nom[i] = nom[i];
    }

    return e;
}

ennemi definir_image(ennemi e, SDL_Texture *image)
{

    e.image = image;

    return e;
}

ennemi definir_sprite(ennemi e, SDL_Rect sprite)
{

    e.sprite = sprite;

    return e;
}

ennemi definir_emplacement_sprite(ennemi e, SDL_Rect emplacement)
{

    e.emplacement_sprite = emplacement;

    return e;
}

// Fonctions de lecture

unsigned int lire_vie(ennemi e)
{

    return e.vie;
}

int lire_vitesse(ennemi e)
{

    return e.vitesse;
}

char *lire_nom(ennemi e)
{

    return e.nom;
}

/*void afficher_nom(ennemi e){

    //printf("%s", lire_nom(e));

    char* nom = lire_nom(e);

    for (int i = 0; i < 20; i++){

        printf("%c", nom[i]);         
    }

    printf("\n");
}
*/

int lire_abscisse(ennemi e)
{

    return e.emplacement_sprite.x;
}

int lire_ordonnee(ennemi e)
{

    return e.emplacement_sprite.y;
}

void afficher_personnage(ennemi e, SDL_Renderer *ecran)
{

    SDL_RenderCopy(ecran, e.image, &e.sprite, &e.emplacement_sprite);
}

// SDL_Renderer *ecran;

// définition du scientifique

//ennemi scientist = definir_nouveau_personnage(ecran, scientist);
/*unsigned int vie_scientist = 200;
int vitesse_scientist = -10;          // négative car il se déplace vers le gauche
const char* nom_scientist = "Scientifique";

definir_vie(scientist, vie_scientist);
definir_vitesse(scientist, vitesse_scientist);
definir_nom(scientist, nom_scientist);*/




/*

A mettre dans ennemis.c

*/


/*SDL_Rect */ ennemi definir_sprite_stf(ennemi e){

    e.sprite.x = 7*TAILLE_STF;
    e.sprite.y = 0;
    e.sprite.h = TAILLE_STF;
    e.sprite.w = TAILLE_STF;

    return e;

}



/*SDL_Rect*/ ennemi definir_emplacement_stf(ennemi e){

    e.emplacement_sprite.x = 600;
    e.emplacement_sprite.y = 620;
    e.emplacement_sprite.w = 100;
    e.emplacement_sprite.h = 80;

    return e;

}






void animer_ennemi(ennemi e, SDL_Renderer *ecran)
{

    int temps_actuel = 0;
    int temps_precedent = 0;

    int parcours = -1; // sens du parcours de la feuille de sprite (-1: vers la gauche)

    bool stop = false;

    temps_actuel = SDL_GetTicks();
    while (temps_actuel - temps_precedent > 100 && stop == false)
    {

        afficher_personnage(e, ecran);
     
        //printf("%dx, %dy\n", e.sprite.x, e.sprite.y);
        e.emplacement_sprite.x -= 10;
        e.sprite.x += parcours * (TAILLE_STF);

        //printf("%dx, %dy\n", e.emplacement_sprite.x, e.emplacement_sprite.y);

        if (e.sprite.x == 0 && e.sprite.y == 0)
        {

            //e.sprite.x = 7 * TAILLE_STF;
            //e.sprite.x = 121;
            //e.sprite.y = 59;
            parcours = 1;
            e.sprite.y += TAILLE_STF;
            //moins = 1;
        }

        if (e.sprite.x == 8 * TAILLE_STF && e.sprite.y == TAILLE_STF)
        {

            e.sprite.x -= TAILLE_STF;
            e.sprite.y += TAILLE_STF;
            parcours = -1;
        }

        if (e.emplacement_sprite.x == -TAILLE_STF || (e.sprite.x == TAILLE_STF && e.sprite.y == 2 * TAILLE_STF))
        {

            stop = true;
            SDL_DestroyTexture(e.image);
        }

        temps_precedent = temps_actuel;
    }

    
}

//lire emplacement...

/*
typedef struct Personnage chat1;
typedef struct Personnage chat2;
*/

/*
void afficher(SDL_Renderer *ecran, SDL_Event evenements, ennemi e) /*, SDL_Rect sprite, SDL_Rect emplacement)*/
/*{

    
    e.sprite = sprite(evenements, r);

    // sprites de base

   

    // animation


    // avant : ennemi est ici une texture

    SDL_RenderCopy(ecran, e.image, &e.sprite, &e.emplacement_sprite);
}

*/

/*
SDL_Rect sprite(SDL_Event evenements, ennemi e)
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
            e.sprite.x += TAILLE_STF;
            //50;
            break;
        default:
            break;
        }
    }

    return e.sprite;
}
*/
/*void afficher_balle(SDL_Renderer *ecran, SDL_Texture *balle, bool afficher) /*, SDL_Rect sprite, SDL_Rect emplacement)*/
//{

/* SDL_Rect position_balle;
    SDL_Rect image = sprite();

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
    sprite.w = TAILLE_STF;
    sprite.h = TAILLE_STF;

    return sprite;
}*/
