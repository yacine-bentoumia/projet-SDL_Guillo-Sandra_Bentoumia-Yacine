#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef STRUCTURES_H
#define STRUCTURES_H


struct Personnage
{

    unsigned int vie;
    int vitesse;
    /*const */
    char nom[20];
    SDL_Texture *image;
    SDL_Rect sprite;          //[NB_SPRITES_RACCOON];
    SDL_Rect position_sprite; //[NB_SPRITES_RACCOON];
};

// elements tels que les balles etc

struct Element
{

    int vitesse; //deplacer

    SDL_Texture *image;
    SDL_Rect sprite;
    SDL_Rect position_sprite;
    int abscisse_reference;
    int ordonnee_reference;
};

// définition du type ennemi

//typedef struct Personnage raccoon;
typedef struct Personnage ennemi;



#endif