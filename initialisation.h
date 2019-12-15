#ifndef INITIALISATION_H
#define INITIALISATION_H


#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"
#include "lecture_map.h"





void initialisation_jeu(int* debutX, int *numSprite, int *positionX, int* positionY, int* affichage_position_x,int *temps_debut,int* temps_debut_balle,
int * temps_fin,int *temps_fin_balle,int *temps_debut_collision,int *temps_fin_collision, int *cmp_missile,int *cmp_balle,int * nb_vie) ;

void niveau_alea(Carte *map1);

#endif