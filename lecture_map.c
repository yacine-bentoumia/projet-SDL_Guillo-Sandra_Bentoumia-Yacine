#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lecture_map.h"
#include "constante.h"

void allouer_tab(char* tab, int taille)
{
    
    tab = malloc((taille) *sizeof(char));
    
    
}

/*void afficher_tab(int *tab, int taille)
{

    for (int i = 0; i < taille; i++)
    {

        printf("%d", tab[i]);
    }

    printf("\n");
}*/


void taille_fichier(const char* nomFichier, int* largeur, int*hauteur, int*taille){
    
    FILE* fichier = NULL; 
    fichier = fopen(nomFichier, "r");
    char caractere_actuel = ' ';
    //int compteur = 0;
    

    if (fichier != NULL)
    {
        
        // Boucle de lecture des caractères un à un
        int t = 0 ;
        int h = 0 ;
        do
        {
            caractere_actuel = fgetc(fichier); // On lit le caractère
            //printf("%c", caractere_actuel); // On l'affiche
            
            if(caractere_actuel != '\n'&& caractere_actuel != EOF){
                t++ ;
            }else{
                //printf("taillefiuchier\n");
                h++ ;
            }

           
        } while (caractere_actuel != EOF); 
        
        *taille = t ;
        *hauteur = h ;
        int l = t/h ;
        *largeur = l ;
        
        
        
        fclose(fichier);
    }
    
    



}

char* lire_fichier(const char *nomFichier, int* hauteur,int* largeur, int* taille)
{
    
    FILE* fichier = NULL; 
    //int caractere_actuel = 0;
    fichier = fopen(nomFichier, "r");
    taille_fichier(nomFichier,largeur,hauteur,taille) ;
    char caractere_actuel = ' ';
    char* tab = NULL ;
    tab = malloc((*taille) *sizeof(char));
    //allouer_tab(tab,SURFACE_MAP);
    int i = 0;

    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractere_actuel = fgetc(fichier); // On lit le caractère
            //printf("%c", caractere_actuel); // On l'affiche
            if(caractere_actuel != '\n'&& caractere_actuel != EOF){
                tab[i] = caractere_actuel;
                //printf("%c",tab[i]);
                i++;
            }//else{printf("\n");}

           
        } while (caractere_actuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        //printf("%d \n",i);
        fclose(fichier);
    }
    /*int kj = 0;
     for(int j = 0 ; j < 45 ; j++){
        for(int k = 0; k < 65; k++){
            printf("%c",tab[(j+k*LARGEUR_TABLEAU)]);
            kj = k+j;
        }
        printf("\n");
        
    }
printf(" kj : %d \n",kj);*/
    //afficher_tab_2D(tab,largeur,hauteur);
    
    /*
    FILE *fichier = fopen(nomFichier, "r");
    int n = 0;

    char c;

    int entier;

    //int cpt = 0;

    int *tab = malloc(SURFACE_MAP * sizeof(int));

    allouer_tab(tab);

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

            if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '9')
            {
                entier = c - '0'; // on convertit le caractère lu en entier interprétable
                //printf("%d\n",entier)
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
*/
    return tab;

}