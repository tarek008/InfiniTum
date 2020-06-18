#pragma once


typedef struct Clochard{// Struct de l'entité secondaire

	int x,y,vx,vy;
	SDL_Surface *image;
	SDL_Rect position;
	SDL_Rect clips[4];
	float frame;
} Clochard;

void CLOCHARD_Init(Clochard *c);
void CLOCHARD_Render(Clochard *c, SDL_Surface **screen);

