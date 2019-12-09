#ifndef LECTURE_MAP_H
#define LECTURE_MAP_H
#include "constante.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"

void allouer_tab(char*tab, int taille);

void afficher_tab(char* tab, int taille);

void taille_fichier(const char* nomFichier, int* largeur, int* hauteur, int*taille);

void lire_fichier(const char *nomFichier, Carte *map);//int* hauteur,int* largeur, int* taille);



#endif