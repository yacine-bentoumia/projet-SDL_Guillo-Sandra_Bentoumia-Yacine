#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef STRUCTURES_H
#define STRUCTURES_H


// structure pouvant être commune à tous les personnages
// ici elle définit seulement les ennemis

struct Personnage
{

    unsigned int vie;
    int vitesse;
    /*const */char nom[20];
    SDL_Texture *image;
    SDL_Rect sprite; //[NB_SPRITES_RACCOON];
    SDL_Rect emplacement_sprite; //[NB_SPRITES_RACCOON];

};



// définition du type ennemi

//typedef struct Personnage raccoon;
typedef struct Personnage ennemi;
//typedef struct ennemi scientifique;


// fonctions d'écriture

ennemi definir_nouveau_personnage(SDL_Renderer *ecran/*, ennemi e*/);
ennemi definir_vie(ennemi e, unsigned int vie);
ennemi definir_vitesse(ennemi e, int vitesse);
ennemi definir_nom(ennemi e, char* nom);
ennemi definir_image(ennemi e, SDL_Texture *image);
ennemi definir_sprite(ennemi e, SDL_Rect sprite);
ennemi definir_emplacement_sprite(ennemi e, SDL_Rect emplacement);



// fonctions de lecture

unsigned int lire_vie(ennemi e);
int lire_vitesse(ennemi e);
char* lire_nom(ennemi e);
void afficher_nom(ennemi e);
int lire_abscisse(ennemi e);
int lire_ordonnee(ennemi e);
void afficher_personnage(ennemi e, SDL_Renderer *ecran);


//lire_image...




// fonctions d'affichage

void afficher(SDL_Renderer *ecran, SDL_Event evenements, ennemi e);
SDL_Rect sprite(SDL_Event evenements, ennemi e);
void annimer_ennemi(ennemi e, SDL_Renderer *ecran);




void afficher_balle(SDL_Renderer *ecran, SDL_Texture *balle, bool afficher);
SDL_Rect sprite_balle();




// definiton du scientifique

ennemi definir_sprite_stf(ennemi e);
ennemi definir_emplacement_stf(ennemi e);



#endif