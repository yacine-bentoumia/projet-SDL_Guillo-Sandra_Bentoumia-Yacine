#include "structures.h"
#include "constante.h"

#ifndef ELEMENTS_H
#define ELEMENTS_H

/*

  Définitions des fonctions de lecture pour les éléments de la map

*/

// fonctions d'écriture générales

element definir_vitesse_element(element e, int vitesse);
element definir_image_element(element e, SDL_Texture *image);

/*element definir_sprite_element(element e, SDL_Rect sprite);
element definir_emplacement_sprite_element(element e, SDL_Rect emplacement);*/

// fonctions de lecture

int lire_vitesse_element(element e);
int lire_abscisse_element(element e);
int lire_ordonnee_element(element e);
void afficher_element(element e, SDL_Renderer *ecran);

// fonctions d'animations

element animer_laser(element e, SDL_Renderer *ecran);
element animer_balle(element e, SDL_Renderer *ecran, int positionX, int position_depart);
element animer_missile(element e, SDL_Renderer *ecran);

// définition du laser par défaut

element definir_sprite_laser(element e);
element definir_emplacement_laser(element e);

// balles

element definir_sprite_balle(element e);
element definir_emplacement_balle1(element e);
element definir_emplacement_balle2(element e);
element definir_emplacement_balle3(element e);
element definir_emplacement_balle4(element e);

// missiles

element definir_sprite_missile(element e);
element definir_emplacement_missile1(element e);
element definir_emplacement_missile2(element e);
element definir_emplacement_missile3(element e);
element definir_emplacement_missile4(element e);

/* correction de l'affichage des objets lors du déplacement :

    si on appuie sur la touche gauche ou la touche droite, les elements (balles, laser)
    ne doivent pas rester fixes par rapport à l'écran

*/

element correction_position_element(element e, SDL_Event evenements, int positionX);


// collision entre un élément et le personnage principal

// s(il y a une collision, l'élément repart à sa position initiale

int collision_element(element e, int positionX, int positionY, int position_initiale);

#endif