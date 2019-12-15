#include "initialisation.h"

void initialisation_jeu(int* debutX, int *numSprite, int *positionX, int* positionY, int* affichage_position_x,int *temps_debut,int* temps_debut_balle,
int * temps_fin,int *temps_fin_balle,int *temps_debut_collision,int *temps_fin_collision, int *cmp_missile,int *cmp_balle,int * nb_vie){

   
  *debutX = 0; // colonne a partir de laquelle on affiche la map
 
  *numSprite = 10;
  *positionX = *debutX + 1; // position sur l'axe des abscisses du perso 
  *positionY = 0; //recupere la position sur l'axe des ordonnees  du perso
  *affichage_position_x = 1; //position d'affichage du personnage
  *temps_debut = 0 ;
  *temps_fin = 0; 
  *temps_debut_balle = 0 ;
  *temps_fin_balle = 0; 
  *temps_debut_collision = 0 ;
  *temps_fin_collision = 0; 
  *cmp_missile = 0 ;
  *cmp_balle = 0 ;
  *nb_vie = 3 ;

}

void niveau_alea(Carte *map1){
  
  srand(time(NULL)); // initialisation de rand
  int fichier = rand()%6;

 
      switch (fichier){
        
        case 0 :
          lire_fichier("map.txt",map1);
          break;
        case 1 :          
          lire_fichier("map1.txt",map1);
          break;
        case 2 :
          lire_fichier("map2.txt",map1);
          break ;
        case 3 :
          lire_fichier("map1.txt",map1);          
          break;
        case 4:
          lire_fichier("map3.txt",map1);         
          break;
        case 5:
          lire_fichier("map2.txt",map1);          
          break;
        default :
          lire_fichier("map.txt",map1);
          break;
        }

}