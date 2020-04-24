#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "joeur.h"


 void initEntite(Entite E[])
{

//loadEntiteImages
 char nomFich[50], nomFich1[25];
int i=1;
int j=49;
char tab[4][20];
char ch[10];


    sprintf(nomFich,"mv1/%d.png",i);
    E[0].enemis[0]=IMG_Load(nomFich);
    E[0].position.x=300;
    E[0].position.y=200;

   sprintf(nomFich,"mv1/%d.png",j);
    E[1].enemis[1]=IMG_Load(nomFich);
    E[1].position.x=700;
    E[1].position.y=500;

    sprintf(nomFich,"mv1/%d.png",j+1);
    E[2].enemis[2]=IMG_Load(nomFich);
    E[2].position.x=900;
    E[2].position.y=500;

    sprintf(nomFich,"mv1/%d.png",j+2);
    E[3].enemis[3]=IMG_Load(nomFich);
    E[3].position.x=500;
    E[3].position.y=10;


  //  strcpy(tab[0],("mv1/1.png"));
   /* tab[1]=("mv1/2.png");
    tab[0]=("mv1/1.png");
    tab[0]=("mv1/1.png");*/


/*
   for(i=1;i<3;i++)
    {
       sprintf(nomFich,"mv1/%d.png",i+1);
       E[i].position.x = E[i-1].position.x + 400;
       E[i].position.y = 200;
       E[i].enemis[0]= IMG_Load(nomFich);
    }
*/

  E[0].sens = 0;

}


void MoveEntiteleft(Entite E[])
{
   E[0].position.x -= 20;
}

void MoveEntiteright(Entite E[])
{
   E[0].position.x += 20;
}



void freeEntite(Entite E[])
{
 	SDL_FreeSurface(E[0].enemis[0]);
        SDL_FreeSurface(E[3].enemis[3]);
        SDL_FreeSurface(E[1].enemis[1]);
        SDL_FreeSurface(E[2].enemis[2]);
}



int position (int posmax , int posmin)
{
int pos;

		srand(time(NULL));
		pos=rand()%(posmax-posmin+1)+posmin;
	return pos;
}


void deplacerEntite(Entite E[], SDL_Surface *screen, SDL_Rect positionecran, int posmax , int posmin , int posmax_x , int posmin_x)
{
 char nomFich[50];

  E[0].position.y = position(posmax,posmin);

 if (E[0].position.x > posmax_x )
  {
     E[0].sens = 0;

      sprintf(nomFich,"mv1/%d.png",22);
      E[0].enemis[0]=IMG_Load(nomFich);



 SDL_BlitSurface(E[0].enemis[22],&positionecran,screen,&(E[0].position));

  }


 if (E[0].position.x < posmin_x )
  {
     E[0].sens = 1;

      sprintf(nomFich,"mv1/%d.png",1);
      E[0].enemis[0]=IMG_Load(nomFich);



  SDL_BlitSurface(E[0].enemis[0],&positionecran,screen,&(E[0].position));
  }

 if (E[0].sens == 1)
  E[0].position.x += 20;

 else if (E[0].sens == 0)
  E[0].position.x -= 20;
}


/*
Debut

Si (E.Position.x> PosMax)
  E.Direction=gauche
 FinSi

 Si (E.Position.x<PosMin)
 E.Direction=droite
 FinSi

Si (E.Direction=droite)
 E.Position.x++ ;

 Sinon   E.Position.x- - ;
FinSi

Fin

*/

void blitEntite(Entite E[] , SDL_Surface *ecran)
{
int i=0;
for(i=0;i<3;i++)
{

SDL_BlitSurface(E[i].enemis[0],NULL,ecran,&(E[i].position));
//SDL_BlitSurface(E[i].enemis[1],NULL,ecran,&(E[i].position));
SDL_Delay(10);

}
//SDL_BlitSurface(E[1].enemis[1],NULL,ecran,&(E[1].position));
//SDL_BlitSurface(E[2].enemis[2],NULL,ecran,&(E[2].position));
//SDL_BlitSurface(E[3].enemis[3],NULL,ecran,&(E[3].position));
}

