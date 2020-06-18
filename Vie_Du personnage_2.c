#include "joeur.h"
  
void initialiserVie2(Vie *vie)
{
	vie->vie_img[0]=IMG_Load("resources/vie 0.png");
	vie->vie_img[1]=IMG_Load("resources/vie 1.png");
	vie->vie_img[2]=IMG_Load("resources/vie 2.png");
	vie->vie_img[3]=IMG_Load("resources/vie 3.png");
	vie->posVie.x=280;
	vie->posVie.y=40;
	vie->valVie=3;
}

