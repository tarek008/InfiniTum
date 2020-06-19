#include "joeur.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
void init_bk(BACKGROUND* b)
{
	char ch[35];
	b->position_collision.x=0;
	b->position_collision.y=0;
	b->bg=IMG_Load("bgg.jpg");
	//b->bg_collision=IMG_Load("bgMask.png");
 b->cam.x=0;
   b->cam.y=0;
   b->cam.w=b->bg->w;
  b->cam.h=b->bg->h;

}
void afficher_bk(BACKGROUND *bk,SDL_Surface *fenetre)
{
	SDL_BlitSurface(bk->bg,&(bk->cam),fenetre,NULL);
}


void scrollingbg(int sens,BACKGROUND *bg,PERSO_PRINCIPALE *p,double xVel)
{
	//camera
		if(p->position.x>700 && -bg->cam.x+bg->cam.w>1210) {bg->cam.x+=xVel;p->position.x=700;}
	if(p->position.x<300 && bg->cam.x>10) {bg->cam.x+=xVel;p->position.x=300;}
	//cam.y+=yVel;
	if(p->position.x>1110 || p->position.x<0) xVel=0;

}

int mapaffiche(SDL_Surface * screen  ,int persoPOS)
{
//EVENT
SDL_Event event ;
  		int r=0 ;
	SDL_PollEvent(&event);
//EVENT

SDL_Surface* bgM,*poiIM;
SDL_Rect posi,poC;
posi.x=0;
posi.y=(512/2)-250/2;
poC.x=persoPOS/2;
poC.y=posi.y+250/2;
char image[50],im2[50];
sprintf(image ,"fathallah/bggMINI2.jpg");
sprintf(im2 ,"fathallah/point.png");

(bgM)=IMG_Load(image);
(poiIM)=IMG_Load(im2);
SDL_BlitSurface((bgM),NULL,screen,&posi) ;
SDL_BlitSurface(poiIM,NULL,screen,&poC) ;
SDL_Flip(screen);

	switch(event.type)
	{
		  case SDL_QUIT:
			/*        *running= 0 ;
                *run = 0;*/
				break ; 

       case SDL_KEYDOWN :
            switch( event.key.keysym.sym )
                {
			  case  SDLK_m:
			  r= 1;
			   break ;

		}
       break ;


	}
  return r ;
}


void miniMapCorner(SDL_Surface *screen,int persoPOS,int verti)
{
SDL_Surface* bgMC,*poiIMC;
SDL_Rect posiC,poCC;
posiC.x=1200-307;
posiC.y=0;
poCC.x=(persoPOS*15)/100+posiC.x;
poCC.y=posiC.y+77/2+((verti-200)*15)/100;
char image[50],im2[50];
sprintf(image ,"fathallah/bgMiniCorner.jpg");
sprintf(im2 ,"fathallah/player1MINI.png");

(bgMC)=IMG_Load(image);
(poiIMC)=IMG_Load(im2);
SDL_BlitSurface((bgMC),NULL,screen,&posiC) ;
SDL_BlitSurface(poiIMC,NULL,screen,&poCC) ;
SDL_Flip(screen);
}

