#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void personnage_jeu(SDL_Renderer* ecran ,int h, int w , int positionX , int positionY , SDL_Texture* perso , int numSprite,SDL_Rect* sprite)  ;

SDL_Rect* sprite_personnage() ;

void deplacement_sur_map (int* debutX, int direction , int* positionX , int* positionY) ;
