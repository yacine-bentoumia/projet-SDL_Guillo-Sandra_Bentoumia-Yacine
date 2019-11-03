#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef STRUCTURES_H
#define STRUCTURES_H


// structure commune à tous les personnages

struct Personnage
{

    unsigned int vie;
    SDL_Texture *image;
    SDL_Rect sprite /*[NB_SPRITES_RACCOON]*/;
    SDL_Rect emplacement_sprite /*[NB_SPRITES_RACCOON]*/;
};



// définition du type raccoon

typedef struct Personnage raccoon;


// fonctions de lecture et d'écriture

raccoon definir_raccoon(SDL_Renderer *ecran, raccoon r);
unsigned int lire_vie_raccoon(raccoon r);
int lire_abscisse_raccoon(raccoon r);


// fonctions d'affichage

void afficher_raccoon(SDL_Renderer *ecran, SDL_Event evenements, raccoon r)  ;
SDL_Rect sprite_raccoon(SDL_Event evenements, raccoon r);
void afficher_balle(SDL_Renderer *ecran, SDL_Texture *balle, bool afficher);
SDL_Rect sprite_balle();


#endif