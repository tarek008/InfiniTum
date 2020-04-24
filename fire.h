#pragma once


typedef struct Clochard{

	int x,y,vx,vy;
	SDL_Surface *image, *image2;
	SDL_Rect position;
	SDL_Rect clips[11];
	SDL_Rect clips2[11];
	float frame;
} Clochard;

void CLOCHARD_Init(Clochard *c);
void CLOCHARD_Render(Clochard *c, SDL_Surface **screen);

