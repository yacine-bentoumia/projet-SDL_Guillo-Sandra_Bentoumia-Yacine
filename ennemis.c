#include "ennemis.h"
#include "structures.h"

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

    e.position_sprite.x = 100;
    e.position_sprite.y = 600;
    e.position_sprite.w = 150;
    e.position_sprite.h = 100;

    return e;
}*/

/*ennemi definir_nouveau_personnage(SDL_Renderer *ecran)
{

    ennemi e;

    e.vie = 0;
    e.vitesse = 0;
    //e.nom = "";
    e.image = NULL;
    //e.sprite = NULL;
    //e.position_sprite = NULL;

    return e;
}
*/
// fonctions d'écriture

ennemi definir_vie(ennemi e, unsigned int vie)
{

    e.vie = vie;

    return e;
}

ennemi definir_vitesse(ennemi e, int vitesse)
{

    e.vitesse = vitesse;
    e.position_sprite.x += vitesse;

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

ennemi definir_position_sprite(ennemi e, SDL_Rect position)
{

    e.position_sprite = position;

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
/*
char *lire_nom(ennemi e)
{

    return e.nom;
}*/

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

    return e.position_sprite.x;
}

int lire_ordonnee(ennemi e)
{

    return e.position_sprite.y;
}

void afficher_personnage(ennemi e, SDL_Renderer *ecran)
{

    SDL_RenderCopy(ecran, e.image, &e.sprite, &e.position_sprite);
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

/*SDL_Rect */
ennemi definir_sprite_stf(ennemi e)
{

    e.sprite.x = 7 * TAILLE_STF;
    e.sprite.y = 0;
    e.sprite.h = TAILLE_STF;
    e.sprite.w = TAILLE_STF;

    return e;
}

/*SDL_Rect*/
ennemi definir_position_stf(ennemi e)
{

    e.position_sprite.x = 600;
    e.position_sprite.y = 620;
    e.position_sprite.w = 100;
    e.position_sprite.h = 80;

    return e;
}

// fonctions de définition

ennemi deplacer_ennemi(ennemi e)
{

    bool stop = false;

    if (e.position_sprite.x < -TAILLE_STF)
        stop = true;

    if (!stop)
    {

        e.position_sprite.x += lire_vitesse(e);
        //e.position_sprite.x -= 10;
        //afficher_personnage(e, ecran);

        //printf("pos: %d\n", e.position_sprite.x);
    }
    return e;
}

ennemi animer_ennemi(ennemi e)
{

    int parcours; // = -1; // sens du parcours de la feuille de sprite (-1: vers la gauche)

    bool stop = false;

    if (e.sprite.x == TAILLE_STF && e.sprite.y == 2 * TAILLE_STF)
    {

        stop = true;
        SDL_DestroyTexture(e.image);
    }

    if (!stop)
    {

        if (e.sprite.x >= TAILLE_STF /*-TAILLE_STF*/ && e.sprite.y == 0)
        {
            parcours = -1;
        }

        if (e.sprite.x == 0 /*-TAILLE_STF*/ && e.sprite.y == 0)
        {
            e.sprite.y += TAILLE_STF;
            parcours = 1;
        }

        if (e.sprite.x >= 0 && e.sprite.y == TAILLE_STF)
        {
            parcours = 1;
        }

        if (e.sprite.x == 8 * TAILLE_STF && e.sprite.y == TAILLE_STF)
        {
            e.sprite.y += TAILLE_STF;
            parcours = -1;
        }

        if (e.sprite.x > TAILLE_STF && e.sprite.y == 2 * TAILLE_STF)
        {
            parcours = -1;
        }

        e.sprite.x += parcours * TAILLE_STF;
        /* printf("parcours: %d\t", parcours);
        printf("num: %d\n", e.sprite.x);*/
    }

    return e;
}

ennemi correction_position_ennemi(ennemi e, SDL_Event evenements, int positionX)
{

    switch (evenements.key.keysym.sym)
    {
    case SDLK_LEFT:
        if (positionX == 0)
        {
            e.position_sprite.x += 17;
        }
        else
        {
            e.position_sprite.x += 25;
        }
        break;
    case SDLK_RIGHT:
        e.position_sprite.x -= 35;
        //("e: %d\n", e.position_sprite.x);
        break;
    }

    //e.position_sprite.x -= 52;

    return e;
}

//lire position...

/*
typedef struct Personnage chat1;
typedef struct Personnage chat2;
*/

/*
void afficher(SDL_Renderer *ecran, SDL_Event evenements, ennemi e) 
//, SDL_Rect sprite, SDL_Rect position)
*/
/*{

    
    e.sprite = sprite(evenements, r);

    // sprites de base

   

    // animation


    // avant : ennemi est ici une texture

    SDL_RenderCopy(ecran, e.image, &e.sprite, &e.position_sprite);
}

*/

/*
SDL_Rect sprite(SDL_Event evenements, ennemi e)
{

    //sprite = malloc(sizeof(SDL_Rect) * NB_CASE_PERSO);

    // animation

    //SDL_Event evenements;

    if (evenements.type == SDL_KEYDOWN)
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
//void afficher_balle(SDL_Renderer *ecran, SDL_Texture *balle, bool afficher)) //, SDL_Rect sprite, SDL_Rect position)
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

                // if (activer_anim == true)
                //printf("true\n");
            //else
                //printf("false\n");
                */

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

    //for (int i = 0; i < NB_CASE_TOURELLE + 1; i++)
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
/*
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
        sprite[i].w = TAILLE_STF;

        //coordonnees x du sprite a afficher
        sprite[i].x = i * 135;

        //coordonnee y du sprite a afficher
        sprite[i].y = 4;
    }

    return sprite;
}*/

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
/*
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

void position_balle1(SDL_Rect sprite)
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
            //printf("posx: %d\n", position.x);
            temps_precedent = temps_actuel;
        }
    }
}*/