#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fire.h"

void CLOCHARD_Init(Clochard *c){
	c->image = IMG_Load("20.png");
	//c->image2 = IMG_Load("2.png");
	c->position.x = 690;
	c->position.y = 230;
	c->vx = 0; 
	c->vy = 0;
	
	for (int i = 0; i < 3; i++ ){
		c->clips[i].x = i*75;
		c->clips[i].y = 0;
		c->clips[i].w = 75;
		c->clips[i].h = 250;
	}
	
	
	c->frame = 0;
}

void CLOCHARD_Render(Clochard *c, SDL_Surface **screen){

	if(c->vx >= 0){

		SDL_BlitSurface(c->image,&c->clips[(int) c->frame],*screen,&c->position);

	}else{
		//SDL_BlitSurface(c->image2,&c->clips2[(int) c->frame],*screen,&c->position);

	}

	c->frame += 0.15f;

	if(c->frame > 3) {
		 c->frame = 0;
		c->vx *= -1;
	}
	//c->position.x = c->vx;

		
}
