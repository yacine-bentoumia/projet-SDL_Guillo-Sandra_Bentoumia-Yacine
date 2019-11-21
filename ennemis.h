#ifndef ENNEMIS_H
#define ENNEMIS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constante.h"
#include "map.h"
#include "fenetreDuJeu.h"
#include "finDeJeu.h"


SDL_Rect sprite_balle1();

void emplacement_balle1(SDL_Renderer *ecran, SDL_Texture *perso, SDL_Rect sprite, int *map);

void deplacement_balle1(SDL_Renderer *ecran, SDL_Texture *perso, SDL_Rect sprite);





void tourelle(SDL_Renderer *ecran, int h, int w, int positionY, SDL_Texture *perso, int numSprite, SDL_Rect sprite, int affichage_position_x);

SDL_Rect sprite_tourelle();

void stf(SDL_Renderer *ecran, SDL_Texture *perso, SDL_Rect *sprite, int numSprite);

SDL_Rect *sprite_stf();

void balle_1(SDL_Renderer *ecran, int h, int w, int positionY, SDL_Texture *perso, int numSprite, SDL_Rect *sprite, int affichage_position_x);

SDL_Rect *sprite_balle_1();

void balle_2(SDL_Renderer *ecran, int h, int w, int positionY, SDL_Texture *perso, int numSprite, SDL_Rect *sprite, int affichage_position_x);

SDL_Rect *sprite_balle_2();

void deplacement_tourelle(int *debutX, int direction, int *positionX, int *positionX_t, int *positionY, int *affichage_position_x);

void deplacement_stf(int *debutX, int direction, int *positionX, int *positionY, int *affichage_position_x);

#endif