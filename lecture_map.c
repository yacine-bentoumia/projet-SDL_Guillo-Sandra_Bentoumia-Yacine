#include "lecture_map.h"


void taille_fichier(const char* nomFichier, int* largeur, int*hauteur, int*taille){
    
    FILE* fichier = NULL; 
    fichier = fopen(nomFichier, "r");
    char caractere_actuel = ' ';
  
    

    if (fichier != NULL)
    {
        
        // Boucle de lecture des caractères un à un
        int t = 0 ;
        int h = 0 ;
        do
        {
            caractere_actuel = fgetc(fichier); // On lit le caractère
            
            
            if(caractere_actuel != '\n'&& caractere_actuel != EOF){
                t++ ;
            }else{
              
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

void lire_fichier(const char *nomFichier, Carte *tab)
{
    
    int hauteur = 0,taille=0,largeur=0;
    
    FILE* fichier = NULL; 
   
    fichier = fopen(nomFichier, "r");
    taille_fichier(nomFichier,&largeur,&hauteur,&taille) ;
    
    tab->largeur = largeur;
    tab->hauteur = hauteur ;
    tab->taille = taille;
    char caractere_actuel = ' ';

    if(tab->carteJeu == NULL){
        
        tab->carteJeu = malloc((taille) *sizeof(char));
        
    }else{
        
        (tab->carteJeu) = (char*)realloc((tab->carteJeu), ((taille) *sizeof(char)));
    }
    
    
    int i = 0;

    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractere_actuel = fgetc(fichier); // On lit le caractère
            
            if(caractere_actuel != '\n'&& caractere_actuel != EOF){
                tab->carteJeu[i] = caractere_actuel;
           
                i++;
            }

           
        } while (caractere_actuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
      
        fclose(fichier);
    }
    

}