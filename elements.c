#include "elements.h"

/*

  Définitions des fonctions des élements

*/

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

  SDL_RenderCopy(ecran, e.image, &e.sprite, &e.emplacement_sprite);
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

element definir_emplacement_laser(element e)
{

  e.emplacement_sprite.x = 760; //135;
  e.emplacement_sprite.y = 265;
  e.emplacement_sprite.h = 430;
  e.emplacement_sprite.w = 100;

  return e;
}

// définition des balles par défaut

element definir_sprite_balle(element e)
{

  e.sprite.x = 0;
  e.sprite.y = 0;
  e.sprite.h = 7;
  e.sprite.w = 16;

  return e;
}

element definir_emplacement_balle1(element e)
{

  e.emplacement_sprite.x = POS_BALLE1;
  e.emplacement_sprite.y = 590;
  e.emplacement_sprite.h = 7;
  e.emplacement_sprite.w = 16;

  return e;
}

element definir_emplacement_balle2(element e)
{

  e.emplacement_sprite.x = POS_BALLE2;
  e.emplacement_sprite.y = 637;
  e.emplacement_sprite.h = 7;
  e.emplacement_sprite.w = 16;

  return e;
}

element definir_emplacement_balle3(element e)
{

  e.emplacement_sprite.x = POS_BALLE3;
  e.emplacement_sprite.y = 620;
  e.emplacement_sprite.h = 7;
  e.emplacement_sprite.w = 16;

  return e;
}

// definition des missiles par défaut

element definir_sprite_missile(element e)
{

  e.sprite.x = 0;
  e.sprite.y = 0;
  e.sprite.h = 150;
  e.sprite.w = 32;

  return e;
}

element definir_emplacement_missile1(element e)
{

  e.emplacement_sprite.x = POS_MISSILE1_X;
  e.emplacement_sprite.y = POS_MISSILE1_Y;
  e.emplacement_sprite.h = 70;
  e.emplacement_sprite.w = 32;

  return e;
}

// collision entre un élément et le personnage principal

int collision_element(element e, int positionX, int positionY, int position_initiale)
{

  int toucher = 0;

  //printf("%d\n", 16 * positionY + 48);

  //perso : 48 de haut, 52 de largeur
  //pos: 1X 40Y

  if (e.emplacement_sprite.x <= 104 && e.emplacement_sprite.x >= 52)
  {
    // printf("x\n");

    if (e.emplacement_sprite.y >= 16 * positionY && e.emplacement_sprite.y <= 16 * positionY + 48)
    {
      //printf("y\n");
      toucher = 1;

      // problème ici
      // e.emplacement_sprite.x = position_initiale;
    }
  }

  return toucher;
}

/*
element definir_emplacement_balle4(element e)
{

    e.emplacement_sprite.x = POS_BALLE4;
    e.emplacement_sprite.y = 590;
    e.emplacement_sprite.h = 7;
    e.emplacement_sprite.w = 16;

    return e;
}*/

/*

  Fonctions d'animation

*/

element animer_laser(element e, SDL_Renderer *ecran)
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

  printf("%d\n", animer);

  return e;
}

element animer_balle(element e, SDL_Renderer *ecran, int positionX, int position_depart)
{

  int position_de_depart = position_depart;
  int position_adaptee;

  if (positionX <= 10)
  {
    position_adaptee = position_de_depart - ((positionX - 1) * LARGEUR_FENETRE / LARGEUR_MAP);
  }

  else
  {
    position_adaptee = position_de_depart - ((positionX - 8) * LARGEUR_FENETRE / LARGEUR_MAP);
  }

  if (e.emplacement_sprite.x > -e.sprite.w)
  {
    e.emplacement_sprite.x -= 10;
  }

  else
  {
    e.emplacement_sprite.x = position_adaptee;
  }
  //printf("pos balle: %d\n", e.emplacement_sprite.x);
  return e;
}

element animer_missile(element e, SDL_Renderer *ecran)
{

  if (e.emplacement_sprite.y < 612)
  {

    e.emplacement_sprite.y += 10;
  }

  else
  {
    e.emplacement_sprite.y = POS_MISSILE1_Y;
  }

  return e;
}

/* correction de l'affichage des objets lors du déplacement :

    si on appuie sur la touche gauche ou la touche droite, les elements (balles, laser)
    ne doivent pas rester fixes par rapport à l'écran

*/

element correction_position_element(element e, SDL_Event evenements, int positionX)
{
  switch (evenements.key.keysym.sym)
  {
  case SDLK_LEFT:
    if (positionX == 0)
    {
      e.emplacement_sprite.x += 17;
    }
    else
    {
      e.emplacement_sprite.x += 25;
    }
    break;
  case SDLK_RIGHT:
    e.emplacement_sprite.x -= 35;
    //printf("e: %d\n", e.emplacement_sprite.x);
    break;
  }

  //e.emplacement_sprite.x -= 52;

  return e;
}