#include "chat2.h"
#include "constante.h"

void afficher_chat2(SDL_Renderer *ecran, SDL_Texture *chat2)
{

    SDL_Rect position_chat2;
    SDL_Rect image = sprite_chat2();

    position_chat2.x = 1300;
    position_chat2.y = 600;
    position_chat2.w = LARGEUR_CHAT;
    position_chat2.h = HAUTEUR_CHAT;

    SDL_RenderCopy(ecran, chat2, &image, &position_chat2);
}

SDL_Rect sprite_chat2()
{
    SDL_Rect sprite;
    //sprite = malloc(sizeof(SDL_Rect) * NB_CASE_PERSO);

    sprite.x = 0;
    sprite.y = 125;
    sprite.w = 95;
    sprite.h = 125;

    return sprite;
}