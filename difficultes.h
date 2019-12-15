#ifndef DIFFICULTES_H
#define DIFFICULTES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lecture_map.h"
#include "map.h"

void nb_de_balle(Carte map1,int* cmp_balle,int* cmp_missile);

void affichage_balle(SDL_Renderer* ecran,SDL_Texture* balle,SDL_Rect* posBalle,int taille);

void copie_de_position(SDL_Rect*posBalle,SDL_Rect*dep_balle,int taille);

void deplacer_balle(SDL_Rect*pos_tab,int w,int taille);

void deplacer_missile(SDL_Rect* pos_tab,int taille,SDL_Rect*tab);


#endif
