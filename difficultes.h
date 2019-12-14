#ifndef DIFFICULTES_H
#define DIFFICULTES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lecture_map.h"
#include "map.h"

int nb_de_balle(Carte map1);

void affichage_balle(SDL_Renderer* ecran,SDL_Texture* balle,SDL_Rect* posBalle,int taille);

void copie_de_position(SDL_Rect*posBalle,SDL_Rect*dep_balle,int taille);

void deplacer_balle(SDL_Rect*pos_tab,int w,int taille);


#endif
