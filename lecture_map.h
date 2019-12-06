#ifndef LECTURE_MAP_H
#define LECTURE_MAP_H

void allouer_tab(char*tab, int taille);

void afficher_tab(char* tab, int taille);

void taille_fichier(const char* nomFichier, int* largeur, int* hauteur, int*taille);

char*lire_fichier(const char *nomFichier, int* hauteur,int* largeur, int* taille);



#endif