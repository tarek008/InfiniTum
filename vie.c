#include "joeur.h"
  
void initialiserVie(Vie *vie)
{
	vie->vie_img[0]=IMG_Load("resources/vie 0.png");
	vie->vie_img[1]=IMG_Load("resources/vie 1.png");
	vie->vie_img[2]=IMG_Load("resources/vie 2.png");
	vie->vie_img[3]=IMG_Load("resources/vie 3.png");
	vie->posVie.x=40;
	vie->posVie.y=40;
	vie->valVie=3;
}
void nbVie(int collision, int *gameOver ,Vie *vie, SDL_Surface *screen)
{
	if ((collision>(3-vie->valVie)) && vie->valVie!=0)
	vie->valVie --;

	 if (vie->valVie==0)
	{
		*gameOver=1;
		SDL_BlitSurface(vie->vie_img[0], NULL, screen,&vie->posVie);
	}
 	else if (vie->valVie==1)
	{
		SDL_BlitSurface(vie->vie_img[1], NULL, screen, &vie->posVie);
	}
	 else if (vie->valVie==2)
	{
		SDL_BlitSurface(vie->vie_img[2], NULL, screen, &vie->posVie);
	}
	 else if (vie->valVie==3)
	{
		SDL_BlitSurface(vie->vie_img[3], NULL, screen, &vie->posVie);
	}
} 
