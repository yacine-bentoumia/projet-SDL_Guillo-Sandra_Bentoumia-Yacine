#include <time.h>
#include "fenetreDuJeu.h"
#include "finDeJeu.h"
#include "gestionDesTouches.h"
#include "constante.h"
#include "map.h"
#include "personnage.h"
#include "lecture_map.h"
#include "menu.h"
#include "difficultes.h"
#include "initialisation.h"


int main(void)
{
  Carte map1 ;  //initialisation de la structure carte
  map1.carteJeu = NULL;
  niveau_alea(&map1);

  SDL_Window *fenetre;  // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre
  bool terminer = false;

  // Créer la fenêtre
  fenetre = fenetreDuJeu();

  //initialisation de l'image du menu
  SDL_Renderer *ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

  //  Sprites des composants de la map
  SDL_Texture *sol = charger_image("sprites/sol.bmp", ecran);
  SDL_Texture *ciel = charger_image("sprites/ciel.bmp", ecran);
  SDL_Texture *troux = charger_image("sprites/trou.bmp", ecran);
  SDL_Texture *obstacle = charger_image("sprites/obstacle.bmp", ecran);
  SDL_Texture *pics = charger_image_transparente("sprites/pics.bmp",ecran,255,0,0);
  SDL_Texture *vie = charger_image_transparente("sprites/vie.bmp" ,ecran ,255,255,255);
  SDL_Texture *gain = charger_image("sprites/win.bmp", ecran); //image du win

  //Sprite du personnage
  SDL_Texture* perso = charger_image_transparente("sprites/mario.bmp", ecran, 0, 115, 0); // image du perso

  //image pour le menu
  SDL_Texture *jouer = charger_image("sprites/raccoon_jouer.bmp", ecran);
  SDL_Texture *option = charger_image("sprites/raccoon_option.bmp", ecran);
  SDL_Texture *niveau = charger_image("sprites/raccoon_niveau.bmp", ecran);
  SDL_Texture *quitter = charger_image("sprites/raccoon_quitter.bmp", ecran);

  //tableau de texture pour le menu
  SDL_Texture *tableau[4] ;
  tableau[0] = jouer ;
  tableau[1] = option ;
  tableau[2] = niveau ;
  tableau[3] = quitter ;

  //menu des options
  SDL_Texture *commande = charger_image("sprites/options.bmp", ecran);
  SDL_Texture *fleche = charger_image("sprites/fleche.bmp", ecran);

  //niveau differents
  SDL_Texture *niv1 = charger_image("sprites/niveau_un.bmp", ecran);
  SDL_Texture *niv2 = charger_image("sprites/niveau_deux.bmp", ecran);
  SDL_Texture *niv3 = charger_image("sprites/niveau_trois.bmp", ecran);
  SDL_Texture *niv4 = charger_image("sprites/niveau_quatre.bmp", ecran);
  SDL_Texture *niv5 = charger_image("sprites/niveau_cinq.bmp", ecran);
  SDL_Texture *niv6 = charger_image("sprites/niveau_six.bmp", ecran);

  //tableau de texture de niveau 
  SDL_Texture *tab_niv[6] ;
  tab_niv[0] = niv1 ;
  tab_niv[1] = niv2 ;
  tab_niv[2] = niv3 ;
  tab_niv[3] = niv4 ;
  tab_niv[4] = niv5 ;
  tab_niv[5] = niv6 ;
  
  // Sprites des différents ennemis

  SDL_Texture *balle = charger_image_transparente("sprites/balle1.bmp", ecran, 0, 128, 255);
  SDL_Texture *tour4 = charger_image_transparente("sprites/tour4.bmp", ecran,54,157,211);
  SDL_Texture *tour5 = charger_image_transparente("sprites/tour5.bmp", ecran,54,157,211);
  SDL_Texture *tour6 = charger_image_transparente("sprites/tour6.bmp", ecran,54,157,211);
  SDL_Texture *tour7 = charger_image_transparente("sprites/tour7.bmp", ecran,54,157,211);
  SDL_Texture *tour8 = charger_image_transparente("sprites/tour8.bmp", ecran,54,157,211);
  SDL_Texture *missile = charger_image_transparente("sprites/missile.bmp", ecran, 246, 246, 246);

  //chargement des images de fin de jeu
  SDL_Texture* perdu = charger_image ("sprites/gameOver.bmp", ecran) ;
  SDL_Texture* winner = charger_image ("sprites/winner.bmp", ecran) ;

  //initialisation des valeurs
  
  int w = 0; // permet de recuperer la largeur de la carte
  int h = 0; // permet de recuperer la hauteur de la carte 
  int debutX = 0; // colonne a partir de laquelle on affiche la map
 
  int numSprite = 10;
  int positionX = debutX + 1; // position sur l'axe des abscisses du perso 
  int positionY = 0; //recupere la position sur l'axe des ordonnees  du perso
  int affichage_position_x = 1; //position d'affichage du personnage
  SDL_Rect *sprite = sprite_personnage(); //tableau de sprite du personnage
  int temps_debut = 0 ;
  int temps_fin = 0; 
  int temps_debut_balle = 0 ;
  int temps_fin_balle = 0; 
  int temps_debut_collision = 0 ;
  int temps_fin_collision = 0; 
  int mode = 0 ;
  int num = 0 ; // numero dans le menu
  int numero = 0 ;  // numero de niveau
  int vitesse = 10 ;
  int cmp_missile = 0 ;
  int cmp_balle = 0 ;
  SDL_Rect dest;

  SDL_Rect* posBalle = NULL;
  SDL_Rect* posMissile = NULL;
  //recupere la position des tours pour pouvoir faire partir les balles
 
  nb_de_balle(map1,&cmp_balle,&cmp_missile); 
   
  posBalle = malloc(cmp_balle*sizeof(SDL_Rect));
  posMissile = malloc(cmp_missile*sizeof(SDL_Rect));
  //besoin d'un tableau pour le deplacement des balles
  SDL_Rect * dep_balle = NULL ;
  dep_balle = malloc(cmp_balle*sizeof(SDL_Rect));
  //creation d'un tableau pour le deplacement des missiles
  SDL_Rect * dep_missile = NULL ;
  dep_missile = malloc(cmp_missile*sizeof(SDL_Rect));

  


  //int direction = 0;
  int nb_vie = 3 ;
  int posX = 0; 
  int posY = 0;

 // Boucle principale
  while (!terminer)
  {
     
    temps_debut = SDL_GetTicks();
    temps_debut_balle = SDL_GetTicks();
    temps_debut_collision = SDL_GetTicks();
    SDL_GetWindowSize(fenetre, &w, &h);
  
    SDL_RenderClear(ecran);
    if(mode == 0){ 
      niveau_alea(&map1);
      initialisation_jeu(&debutX, &numSprite, &positionX, &positionY, &affichage_position_x,&temps_debut,&temps_debut_balle,
&temps_fin,&temps_fin_balle,&temps_debut_collision,&temps_fin_collision, &cmp_missile,&cmp_balle,&nb_vie);
      nb_de_balle(map1,&cmp_balle,&cmp_missile);
       nb_de_balle(map1,&cmp_balle,&cmp_missile);
        if(cmp_balle != 0){
          posBalle = (SDL_Rect*)realloc((posBalle), ((cmp_balle) *sizeof(SDL_Rect)));
          dep_balle = (SDL_Rect*)realloc((dep_balle), ((cmp_balle) *sizeof(SDL_Rect)));
        }

        if(cmp_missile != 0){
          posMissile = (SDL_Rect*)realloc((posMissile), ((cmp_missile) *sizeof(SDL_Rect)));
          dep_missile = (SDL_Rect*)realloc((dep_missile), ((cmp_missile) *sizeof(SDL_Rect)));
          }
      choix_menu(ecran,tableau[num]) ;
    }
    else if (mode == 1){
      
      carteDuJeu(ecran, sol, ciel, troux, obstacle, tour4, tour5, tour6, tour7, tour8, w, h, debutX,gain, map1,pics,posBalle,cmp_balle,posMissile,cmp_missile); // affiche la map   
      if(temps_debut_balle - temps_fin_balle  > 1500){
        copie_de_position(posBalle,dep_balle,cmp_balle);
        copie_de_position(posMissile,dep_missile,cmp_missile);
        temps_fin_balle = temps_debut_balle;
      }
      deplacer_balle(dep_balle, w,cmp_balle);
      deplacer_missile(dep_missile,cmp_missile,posMissile);
      affichage_balle(ecran,balle,dep_balle,cmp_balle);
      affichage_balle(ecran,missile,dep_missile,cmp_missile);
      personnage_jeu(ecran, h, w, positionY, perso, numSprite, sprite, affichage_position_x,map1);
//
      if(temps_debut_collision - temps_fin_collision  > 500){
        if( collision_balle(affichage_position_x,positionY,map1,cmp_balle,dep_balle ,h,w) || collision_missile(affichage_position_x, positionY,map1,cmp_missile, dep_missile,h, w)){
          nb_vie--;
          temps_fin_collision = temps_debut_collision;
        }
      }

      nb_vie_perso(positionX,positionY,map1,&nb_vie,&posX,&posY);
      vie_du_personnage(ecran,vie,nb_vie);
   
      if (nb_vie == 0){
        gameOver(ecran,perdu);
         mode = 0;
      }

      if (!collision_pied(positionX, positionY, map1)){
        if (!trou(positionX, positionY, map1)){
          gravite(1 , &positionY,map1);
        }
        else {
         gameOver(ecran,perdu);
          mode = 0;
        }
     
      }
      if (gagner(positionX, positionY,map1)){
        win(ecran,winner);
        niveau_alea(&map1);
        initialisation_jeu(&debutX, &numSprite, &positionX, &positionY, &affichage_position_x,&temps_debut,&temps_debut_balle,
        &temps_fin,&temps_fin_balle,&temps_debut_collision,&temps_fin_collision, &cmp_missile,&cmp_balle,&nb_vie);
        nb_de_balle(map1,&cmp_balle,&cmp_missile);
      } 

    }else if(mode == 2){
      
      choix_option( ecran,commande,fleche,dest,h,w);
      
    }else if(mode == 3){      
      
      choix_niveau(ecran, tab_niv[numero]);
      switch (numero){
        case 0 :
          lire_fichier("map.txt",&map1);
          break;
        case 1 :          
          lire_fichier("map1.txt",&map1);
          break;
        case 2 :
          lire_fichier("map2.txt",&map1);
          break ;
        case 3 :
          lire_fichier("map3.txt",&map1);          
          break;
        case 4:
          lire_fichier("map4.txt",&map1);         
          break;
        case 5:
          lire_fichier("map5.txt",&map1);          
          break;
        default :
          lire_fichier("map.txt",&map1);
          break;
        }
        
        nb_de_balle(map1,&cmp_balle,&cmp_missile);
        if(cmp_balle != 0){
          posBalle = (SDL_Rect*)realloc((posBalle), ((cmp_balle) *sizeof(SDL_Rect)));
          dep_balle = (SDL_Rect*)realloc((dep_balle), ((cmp_balle) *sizeof(SDL_Rect)));
        }

        if(cmp_missile != 0){
          posMissile = (SDL_Rect*)realloc((posMissile), ((cmp_missile) *sizeof(SDL_Rect)));
          dep_missile = (SDL_Rect*)realloc((dep_missile), ((cmp_missile) *sizeof(SDL_Rect)));
          }
        
        
        
    }
    
    SDL_RenderPresent(ecran);
    if (SDL_PollEvent(&evenements))
    {
      gestionTouche(evenements, ecran, &terminer, &debutX, &numSprite, &positionX, &positionY, &affichage_position_x ,&mode,&num,&numero,map1,&vitesse,h,w,perdu);
    }
    temps_fin = SDL_GetTicks();
    if(temps_fin - temps_debut < 30){
      SDL_Delay(30-(temps_fin - temps_debut));
    }
    
  }
  // Liberation de mémoire
  free(sprite);
  free(posBalle);
  free(posMissile) ;
  free(dep_balle);
  free(dep_missile);
  SDL_DestroyTexture(ciel);
  SDL_DestroyTexture(sol);
  SDL_DestroyTexture(troux);
  SDL_DestroyTexture(obstacle);
  SDL_DestroyTexture(perso);
  SDL_DestroyTexture(gain);
  SDL_DestroyWindow(fenetre);
  SDL_DestroyTexture(tour4);
  SDL_DestroyTexture(tour5);
  SDL_DestroyTexture(tour6);
  SDL_DestroyTexture(tour7);
  SDL_DestroyTexture(tour8);
  SDL_DestroyTexture(jouer);
  SDL_DestroyTexture(option);
  SDL_DestroyTexture(fleche);
  SDL_DestroyTexture(niveau);
  SDL_DestroyTexture(quitter);
  SDL_DestroyTexture(pics);
  SDL_DestroyTexture(vie);

  SDL_DestroyTexture(winner);
  SDL_DestroyTexture(perdu);

  SDL_DestroyTexture(niv1);
  SDL_DestroyTexture(niv2);
  SDL_DestroyTexture(niv3);
  SDL_DestroyTexture(niv4);
  SDL_DestroyTexture(niv5);
  SDL_DestroyTexture(niv6);

  SDL_DestroyTexture(balle);
  SDL_DestroyTexture(missile);

  free(map1.carteJeu);
  
  SDL_DestroyRenderer(ecran);
  SDL_DestroyWindow(fenetre);

  SDL_Quit();
  return 0;
}