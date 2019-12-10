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
    /*const */
    char nom[20];
    SDL_Texture *image;
    SDL_Rect sprite;             //[NB_SPRITES_RACCOON];
    SDL_Rect emplacement_sprite; //[NB_SPRITES_RACCOON];
};

// elements tels que les balles etc

struct Element
{

    int vitesse; //deplacer

    SDL_Texture *image;
    SDL_Rect sprite;
    SDL_Rect emplacement_sprite;
};

// définition du type ennemi

//typedef struct Personnage raccoon;
typedef struct Personnage ennemi;
//typedef struct ennemi scientifique;
typedef struct Element element;

/*
void afficher_balle(SDL_Renderer *ecran, SDL_Texture *balle, bool afficher);
SDL_Rect sprite_balle();*/

#endif