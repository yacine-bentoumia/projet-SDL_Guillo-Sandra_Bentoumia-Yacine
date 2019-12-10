#ifndef ENNEMIS_H
#define ENNEMIS_H

#include "constante.h"
#include "structures.h"

// fonctions d'écriture

ennemi definir_nouveau_personnage(SDL_Renderer *ecran /*, ennemi e*/);
ennemi definir_vie(ennemi e, unsigned int vie);
ennemi definir_vitesse(ennemi e, int vitesse);
ennemi definir_nom(ennemi e, char *nom);
ennemi definir_image(ennemi e, SDL_Texture *image);
/*ennemi definir_sprite(ennemi e, SDL_Rect sprite);
ennemi definir_emplacement_sprite(ennemi e, SDL_Rect emplacement);*/

// fonctions de lecture

unsigned int lire_vie(ennemi e);
int lire_vitesse(ennemi e);
char *lire_nom(ennemi e);
void afficher_nom(ennemi e);
int lire_abscisse(ennemi e);
int lire_ordonnee(ennemi e);
void afficher_personnage(ennemi e, SDL_Renderer *ecran);

//lire_image...

// fonctions d'affichage

void afficher(SDL_Renderer *ecran, SDL_Event evenements, ennemi e);
SDL_Rect sprite(SDL_Event evenements, ennemi e);
/*int*/
ennemi animer_ennemi(ennemi e, SDL_Renderer *ecran);
ennemi deplacer_ennemi(ennemi e, SDL_Renderer *ecran);

// definiton du scientifique par défaut

ennemi definir_sprite_stf(ennemi e);
ennemi definir_emplacement_stf(ennemi e);

/* correction de l'affichage des objets lors du déplacement :

    si on appuie sur la touche gauche ou la touche droite, les ennemis
    ne doivent pas rester fixes par rapport à l'écran

*/

ennemi correction_position_ennemi(ennemi e, SDL_Event evenements, int positionX);

/*
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
*/
#endif