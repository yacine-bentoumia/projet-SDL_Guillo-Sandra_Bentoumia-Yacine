#include "structures.h"
#include "constante.h"
#include "map.h"
#include "personnage.h"

#ifndef ELEMENTS_H
#define ELEMENTS_H

/*

  Définitions des fonctions de lecture pour les éléments de la map

*/

// création d'un élément

element creer_balle1(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1);
element creer_balle2(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1);
element creer_balle3(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1);
element creer_balle4(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1);

element creer_missile1(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1);

element creer_explosion1(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1);

// fonctions d'écriture générales

element definir_vitesse_element(element e, int vitesse);
element definir_image_element(element e, SDL_Texture *image);

/*element definir_sprite_element(element e, SDL_Rect sprite);
element definir_position_sprite_element(element e, SDL_Rect position);*/

// fonctions de lecture

int lire_vitesse_element(element e);
int lire_abscisse_element(element e);
int lire_ordonnee_element(element e);
int lire_abscisse_reference(element e);
int lire_ordonnee_reference(element e);
void afficher_element(element e, SDL_Renderer *ecran);

// fonctions d'animations

element animer_laser(element e);
element animer_balle(element e, int largeur);
element animer_missile(element e, int largeur, int hauteur, Carte map1);

bool activer_explosion(element m, int largeur, int hauteur);
element animer_explosion(element e, element m, SDL_Renderer *ecran);

// définition du laser par défaut

element definir_sprite_laser(element e);
element definir_position_laser(element e, int largeur, int hauteur, Carte map1);

// balles

element definir_sprite_balle(element e, int largeur, int hauteur, Carte map1);
element definir_position_balle1(element e, int largeur, int hauteur, Carte map1);
element definir_position_balle2(element e, int largeur, int hauteur, Carte map1);
element definir_position_balle3(element e, int largeur, int hauteur, Carte map1);
element definir_position_balle4(element e, int largeur, int hauteur, Carte map1);

// missiles

element definir_sprite_missile(element e);
element definir_position_missile1(element e, int largeur, int hauteur, Carte map1);
element definir_position_missile2(element e, int largeur, int hauteur, Carte map1);
element definir_position_missile3(element e, int largeur, int hauteur, Carte map1);
element definir_position_missile4(element e, int largeur, int hauteur, Carte map1);

// explosion

element definir_sprite_explosion(element e);
element definir_position_explosion1(element e, int largeur, int hauteur, Carte map1);
element definir_position_explosion2(element e, int largeur, int hauteur, Carte map1);
element definir_position_explosion3(element e, int largeur, int hauteur, Carte map1);
element definir_position_explosion4(element e, int largeur, int hauteur, Carte map1);

/* correction de l'affichage des objets lors du déplacement :

    si on appuie sur la touche gauche ou la touche droite, les elements (balles, laser)
    ne doivent pas rester fixes par rapport à l'écran

*/

element correction_position_element(element e, SDL_Event evenements, int positionX, int positionY, int direction, int largeur, Carte map1);

// collision entre un élément et le personnage principal

// s(il y a une collision, l'élément repart à sa position initiale

int collision_element(element e, int positionY, int largeur, int hauteur, Carte map1);

#endif