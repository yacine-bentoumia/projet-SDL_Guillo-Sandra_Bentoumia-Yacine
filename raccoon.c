#include "raccoon.h"
#include "constante.h"

void afficher_raccoon(SDL_Renderer *ecran, SDL_Texture *raccoon)/*, SDL_Rect sprite, SDL_Rect emplacement_raccoon)*/
{

    SDL_Rect position_raccoon;
    SDL_Rect image = sprite_raccoon();

    position_raccoon.x = 100;
    position_raccoon.y = 600;
    position_raccoon.w = 150;
    position_raccoon.h = 100;

    SDL_RenderCopy(ecran, raccoon, &image, &position_raccoon);
}

SDL_Rect sprite_raccoon()
{
    SDL_Rect sprite;
    //sprite = malloc(sizeof(SDL_Rect) * NB_CASE_PERSO);

    sprite.x = 110;
    sprite.y = 142;
    sprite.w = LARGEUR_RACCOON;
    sprite.h = HAUTEUR_RACCOON;

    return sprite;
}