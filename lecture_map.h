#ifndef LECTURE_MAP_H
#define LECTURE_MAP_H

void allouer_tab(int *tab, int taille);
void desallouer_tab(int *tab, int taille);
void afficher_tab(int* tab, int taille);
//void taille_fichier(const char *nomFichier, int *nbLig, int *nbCol);
int *lire_fichier(const char *nomFichier);

int longueur_ligne(const char *nomFichier);

//bool est_correct(char c):

#endif