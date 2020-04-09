#include "joeur.h"

void init_bk(BACKGROUND* b)
{
	char ch[35];
	b->position_collision.x=0;
	b->position_collision.y=0;
	b->bg=IMG_Load("bg.png");
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

