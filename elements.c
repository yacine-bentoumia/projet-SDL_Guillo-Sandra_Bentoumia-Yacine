#include "elements.h"

/*

  Définitions des fonctions des élements

*/

// création d'un élément

element creer_missile1(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1)
{

  e = definir_vitesse_element(e, vitesse);
  e = definir_image_element(e, image);
  e = definir_sprite_missile(e);
  e = definir_position_missile1(e, largeur, hauteur, map1);

  return e;
}

element creer_balle1(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1)
{

  e = definir_vitesse_element(e, vitesse);
  e = definir_image_element(e, image);
  e = definir_sprite_balle(e, largeur, hauteur, map1);
  e = definir_position_balle1(e, largeur, hauteur, map1);

  return e;
}

element creer_balle2(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1)
{

  e = definir_vitesse_element(e, vitesse);
  e = definir_image_element(e, image);
  e = definir_sprite_balle(e, largeur, hauteur, map1);
  e = definir_position_balle2(e, largeur, hauteur, map1);

  return e;
}
//364 --> 343
element creer_balle3(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1)
{

  e = definir_vitesse_element(e, vitesse);
  e = definir_image_element(e, image);
  e = definir_sprite_balle(e, largeur, hauteur, map1);
  e = definir_position_balle3(e, largeur, hauteur, map1);

  return e;
}
/*
element creer_explosion1(element e, int vitesse, SDL_Texture *image, int largeur, int hauteur, Carte map1)
{

  e = definir_vitesse_element(e, vitesse);
  e = definir_image_element(e, image);
  e = definir_sprite_explosion(e);
  e = definir_position_explosion1(e, largeur, hauteur, map1);

  return e;
}*/

// fonctions de construction générales

element definir_vitesse_element(element e, int vitesse)
{

  e.vitesse = vitesse;

  return e;
}

element definir_image_element(element e, SDL_Texture *image)
{

  e.image = image;

  return e;
}

void afficher_element(element e, SDL_Renderer *ecran)
{

  SDL_RenderCopy(ecran, e.image, &e.sprite, &e.position_sprite);
}

// définition du laser par défaut

element definir_sprite_laser(element e)
{

  e.sprite.x = 0;
  e.sprite.y = 0;
  e.sprite.h = 878;
  e.sprite.w = 162;

  return e;
}
/*
element definir_position_laser(element e, int largeur, int hauteur, Carte map1)
{

  e.position_sprite.x = 760; //135;
  e.position_sprite.y = 265;
  e.position_sprite.h = 430;
  e.position_sprite.w = 100;

  return e;
}*/

// définition des balles par défaut

element definir_sprite_balle(element e, int largeur, int hauteur, Carte map1)
{

  e.sprite.x = 0;
  e.sprite.y = 0;
  e.sprite.h = hauteur_une_case(hauteur, map1) / 3;
  e.sprite.w = largeur_une_case(largeur) / 3;

  //printf(".w %d .h%d\n", e.sprite.w, e.sprite.h);

  return e;
}

element definir_position_balle1(element e, int largeur, int hauteur, Carte map1)
{

  e.position_sprite.w = largeur_une_case(largeur) / 3;
  e.position_sprite.h = hauteur_une_case(hauteur, map1) / 2;

  e.abscisse_reference = 6 * largeur_une_case(largeur) - e.position_sprite.w;
  e.ordonnee_reference = 37 * hauteur_une_case(hauteur, map1) - hauteur_une_case(hauteur, map1)/2; //- e.position_sprite.h / 10;

  //e.position_sprite.x = NULL;//e.ordonnee_reference;
  e.position_sprite.y = e.ordonnee_reference;

 // printf("x %d, y %d\n", e.position_sprite.x, e.position_sprite.y);
  //printf("larg %d, haut %d\n", largeur_une_case(largeur), hauteur_une_case(hauteur, map1));

/*
  e.position_sprite.x = e.abscisse_reference;
  e.position_sprite.y = e.ordonnee_reference;*/

  /*if (e.position_sprite.w != 0){

  printf("w %d, h %d\n", e.position_sprite.w, e.position_sprite.h);
  printf("larg %d, haut %d\n", largeur_une_case(largeur), hauteur_une_case(hauteur, map1));

  }*/
  /*printf("abs ref: %d\t", lire_abscisse_reference(e));
  printf("ord ref: %d\n", lire_ordonnee_reference(e));*/
  //printf("larg: %d\n", largeur);

  return e;
}

element definir_position_balle2(element e, int largeur, int hauteur, Carte map1)
{

  e.position_sprite.w = largeur_une_case(largeur) / 3;
  e.position_sprite.h = hauteur_une_case(hauteur, map1) / 2;

  e.abscisse_reference = 13 * largeur_une_case(largeur) - e.position_sprite.w;
  e.ordonnee_reference = 40 * hauteur_une_case(hauteur, map1) - hauteur_une_case(hauteur, map1)/2;// - e.position_sprite.h + e.position_sprite.h / 2;

  e.position_sprite.x = e.abscisse_reference;
  e.position_sprite.y = e.ordonnee_reference;

  return e;
}

element definir_position_balle3(element e, int largeur, int hauteur, Carte map1)
{

  e.position_sprite.w = largeur_une_case(largeur) / 3;
  e.position_sprite.h = hauteur_une_case(hauteur, map1) / 2;

  e.abscisse_reference = largeur - e.position_sprite.w;
  e.ordonnee_reference = 31 * hauteur_une_case(hauteur, map1);

  e.position_sprite.x = e.abscisse_reference;
  e.position_sprite.y = e.ordonnee_reference;

  return e;
}

// definition des missiles par défaut

element definir_sprite_missile(element e)
{

  e.sprite.x = 0;
  e.sprite.y = 0;
  e.sprite.h = 88;
  e.sprite.w = 32;

  return e;
}

element definir_position_missile1(element e, int largeur, int hauteur, Carte map1)
{

  e.position_sprite.w = largeur_une_case(largeur) / 2 + largeur_une_case(largeur) / 8;
  e.position_sprite.h = 5 * hauteur_une_case(hauteur, map1) - hauteur_une_case(hauteur, map1) / 2;

  e.abscisse_reference = 9 * largeur_une_case(largeur) + largeur_une_case(largeur) / 5;
  e.ordonnee_reference = 4 * hauteur_une_case(hauteur, map1) + hauteur_une_case(hauteur, map1) / 5;

  e.position_sprite.x = e.abscisse_reference;
  e.position_sprite.y = e.ordonnee_reference;

  /*if (e.position_sprite.w != 0)
  {

    printf("w %d, h %d\n", e.position_sprite.w, e.position_sprite.h);
    printf("larg %d, haut %d\n", largeur_une_case(largeur), hauteur_une_case(hauteur, map1));
    printf("posx %d, posy %d\n", e.position_sprite.x, e.position_sprite.y);
  }*/

  return e;
}

// explosion

element definir_sprite_explosion(element e)
{

  //SDL_Rect *tab = malloc(NB_EXPLOSIONS * sizeof(SDL_Rect));

  e.sprite.x = 0;
  e.sprite.y = 0;
  e.sprite.h = HAUTEUR_SPRITE_EXPLOSION / 3;
  e.sprite.w = LARGEUR_SPRITE_EXPLOSION / 8;

  return e;
}
/*
element definir_position_explosion1(element e, int largeur, int hauteur, Carte map1)
{

  e.position_sprite.x = POS_MISSILE1_X;
  e.position_sprite.y = 716 - 32 - 70;
  e.position_sprite.h = 70;
  e.position_sprite.w = 32;

  return e;
}*/

// fonction de lecture

int lire_abscisse_reference(element e)
{

  return e.abscisse_reference;
}

int lire_ordonnee_reference(element e)
{

  return e.ordonnee_reference;
}

// collision entre un élément et le personnage principal

int collision_element(element e, int positionY, int largeur, int hauteur, Carte map1)
{

  int toucher = 0;

  //printf("%d\n", 16 * positionY + 48);

  //perso : 48 de haut, 52 de largeur
  //pos: 1X 40Y

  if (e.position_sprite.x <= 2 * largeur_une_case(largeur) && e.position_sprite.x >= largeur_une_case(largeur))
  {
    // printf("x\n");

    if (e.position_sprite.y >= hauteur_une_case(hauteur, map1) * positionY)
    {

      if (e.position_sprite.y <= hauteur_une_case(hauteur, map1) * positionY + 3 * hauteur_une_case(hauteur, map1))
      {
        //printf("y\n");
        toucher = 1;

        // problème ici
        // e.position_sprite.x = position_initiale;
      }
    }
  }

  return toucher;
}

/*
element definir_position_balle4(element e)
{

    e.position_sprite.x = POS_BALLE4;
    e.position_sprite.y = 590;
    e.position_sprite.h = 7;
    e.position_sprite.w = 16;

    return e;
}*/

/*

  Fonctions d'animation

*/

element animer_laser(element e)
{

  int animer = 0;

  if (animer == 0)
  {
    //afficher_element(e, ecran);
    animer = 1;
  }
  //printf("%d\n", animer);
  else if (animer == 1)
  {
    e.sprite.x += e.sprite.w;
    //afficher_element(e, ecran);
    animer = 2;
  }
  //printf("%d\n", animer);
  else if (animer == 2)
  {
    e.sprite.x = 0;
    animer = 0;
  }

  //printf("%d\n", animer);

  return e;
}

element animer_balle(element e, int largeur)
{

  /*
  e.position.x = abscisse_reference
  */

  //e.position_sprite.x = lire_abscisse_reference(e);

  //printf("pos sprite: %d\n", e.position_sprite.x);
  /* int position_adaptee;

  if (positionX <= 10)
  {
    position_adaptee = e.position_sprite.x - ((positionX - 1) * largeur / LARGEUR_MAP);
    printf("pos ad: %d\n", position_adaptee);
  }*/

  /* else
  {
    position_adaptee = e.position_sprite.x - ((positionX - 8) * LARGEUR_FENETRE / LARGEUR_MAP);
  }*/
/*
  if (e.position_sprite.x == NULL){

  e.position_sprite.x = lire_abscisse_reference(e);
  }*/

  if (e.position_sprite.x > -e.sprite.w)
  {
    e.position_sprite.x -= largeur / 100; //10
  }

  //printf("larg/100: %d\n", largeur/100);

  else
  {
    e.position_sprite.x = lire_abscisse_reference(e);
  }

  /* else
  {*/
  //e.position_sprite.x = position_adaptee;
  // }
  //printf("pos balle: %d\n", e.position_sprite.x);
  return e;
}

element animer_missile(element e, int largeur, int hauteur, Carte map1)
{
  //612
  if (e.position_sprite.y < 30 * hauteur_une_case(hauteur, map1))
  {

    e.position_sprite.y += hauteur_une_case(hauteur, map1) / 2;
  }

  else
  {
    e.position_sprite.y = POS_MISSILE1_Y;
  }

  if (e.sprite.x == 0)
  {

    e.sprite.x += 32;
  }

  else if (e.sprite.x == 32)
  {

    e.sprite.x = 0;
  }

  if (largeur != 0)
  {

    //printf("w %d, h %d\n", e.position_sprite.w, e.position_sprite.h);
    //printf("larg %d, haut %d\n", largeur_une_case(largeur), hauteur_une_case(hauteur, map1));
    //printf("posx %d, posy %d\n", e.position_sprite.x, e.position_sprite.y);
  }

  return e;
}

/*
bool activer_explosion(element m, int largeur, int hauteur)
{

  bool activer = false;

  if (m.position_sprite.y == 614)
  {
    activer = true;
  }

  return activer;
}
*/
/*element animer_explosion(element e, element m, SDL_Renderer *ecran)
{*/

  /*bool animer; //702

  //animer = true; //

  if (m.position_sprite.y == 614 ) //716-32-88
  {

    afficher_element(e, ecran);
    animer = true;
  }*/

 /* int temps_precedent = 0;
  int temps_actuel = 0;

  while (e.sprite.x < LARGEUR_SPRITE_EXPLOSION && e.sprite.y < 2 * HAUTEUR_EXPLOSION)
  {

    temps_actuel = SDL_GetTicks();

    if (temps_actuel - temps_precedent > 50)
    {

      if (e.sprite.x == LARGEUR_SPRITE_EXPLOSION - LARGEUR_EXPLOSION && e.sprite.y == 0)
      {

        e.sprite.x = 0;
        e.sprite.y = HAUTEUR_EXPLOSION;
      }

      if (e.sprite.x == LARGEUR_SPRITE_EXPLOSION - LARGEUR_EXPLOSION && e.sprite.y == HAUTEUR_EXPLOSION)
      {

        e.sprite.x = 0;
        e.sprite.y = 2 * HAUTEUR_EXPLOSION;
      }

      e.sprite.x += LARGEUR_EXPLOSION;
      temps_precedent = temps_actuel;
    }

    //affichage: e = definir_nouvel_position(element e, int position);
  }
*/
  /*if (e.sprite.x == LARGEUR_SPRITE_EXPLOSION && e.sprite.y == 2 * HAUTEUR_EXPLOSION)
  {
    //animer = false;
    e.sprite.x = 0;
    e.sprite.y = 0;
  }*/

  /*if (e.sprite.x < LARGEUR_SPRITE_EXPLOSION && e.sprite.y < 2 * HAUTEUR_EXPLOSION)
  {

    e.sprite.x += LARGEUR_EXPLOSION;
  }*/
/**
  return e;
}*/

/* correction de l'affichage des objets lors du déplacement :

    si on appuie sur la touche gauche ou la touche droite, les elements (balles, laser)
    ne doivent pas rester fixes par rapport à l'écran

*/
//, int *debutX)
element correction_position_element(element e, SDL_Event evenements, int positionX, int positionY, int direction, int largeur, Carte map1)
{

  //int pos = positionX - 1;

  //printf("positionX %d, pos %d\t", positionX, pos);

  //printf("positionX %d\n", positionX);

  switch (evenements.key.keysym.sym)
  {
  case SDLK_LEFT:
    direction = -1;
    break;
  case SDLK_RIGHT:
    direction = 1;
    break;
  }
  //30
  if (positionX == 0 || positionX == 1 || collision(direction, positionX, positionY, map1))
  {

    e.abscisse_reference += 0;
  }

  else
  {
    //e.abscisse_reference -= direction * ((positionX-pos)*largeur_une_case(largeur))/2;

    e.abscisse_reference -= (direction * largeur_une_case(largeur)) / 2;

    //e.abscisse_reference -= (direction * (positionX - *debutX) * largeur_une_case(largeur))/2;
  }

  //printf("pos %d deb %d diff %d\n", positionX, *debutX, positionX - *debutX);
  //printf("ref: %d\n", e.abscisse_reference);

  /*
  else
  {
    nouvelle_position += 1;
  }*/

  /*else
    {
      e.abscisse_reference += largeur_une_case(largeur) / 2;
    }*/

  /*if (collision(direction, positionX, positionY, map1))
  {

    e.abscisse_reference += 0;
  }*/
  /*
  else
  {
    nouvelle_position -= 1;
  }*/

  // else
  // {

  //e.abscisse_reference -= largeur_une_case(largeur) / 2;

  //e.abscisse_reference -= (positionX-1)*largeur_une_case(largeur);

  //  e.abscisse_reference -= largeur_une_case(largeur);

  //  printf("ref: %d\n", e.abscisse_reference);

  // } //35;
  //printf("e: %d\n", e.position_sprite.x);

  //e.abscisse_reference = (positionX + nouvelle_position) * largeur_une_case(largeur);

  //e.position_sprite.x -= 52;

  /*printf("%d\t", positionX - pos);
  printf("%d\t", e.abscisse_reference);*/

  return e;
}