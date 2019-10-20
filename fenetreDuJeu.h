#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constante.h"



SDL_Window* fenetreDuJeu() ;

SDL_Texture *charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b);

SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer*renderer) ;