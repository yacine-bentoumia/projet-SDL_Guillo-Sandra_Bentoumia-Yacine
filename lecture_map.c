#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lecture_map.h"
#include "constante.h"

void allouer_tab(int *tab, int taille)
{

    for (int i = 0; i < taille; i++)
    {

        tab[i] = NULL;
    }
}

void afficher_tab(int *tab, int taille)
{

    for (int i = 0; i < taille; i++)
    {

        printf("%d", tab[i]);
    }

    printf("\n");
}

int *lire_fichier(const char *nomFichier)
{

    FILE *fichier = fopen(nomFichier, "r");
    int n = 0;

    char c;

    int entier;

    //int cpt = 0;

    int *tab = malloc(SURFACE_MAP * sizeof(int));

    allouer_tab(tab, SURFACE_MAP);

    if (fichier == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
    }
    else
    {

        rewind(fichier);

        for (int i = 0; i < SURFACE_MAP; i++)
        {

            fscanf(fichier, "%c", &c);

            if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5')
            {
                entier = c - '0'; // on convertit le caractère lu en entier interprétable
                tab[i] = entier;
                //cpt++;
            }
            else
            {

                fseek(fichier, 1, SEEK_CUR); // sinon on passe au caractere suivant
                //n++;
            }
        }
        // printf("%d\n", cpt);
        // printf("%d\n", n);

        fclose(fichier);
    }

    //afficher_tab(tab, SURFACE_MAP);

    return tab;
}