#include "joeur.h"
 void init_persoP2(PERSO_PRINCIPALE *p)
{

 p->position.x=600;
  p->position.y=200;
  p->position.w=1200;
  p->position.h=600;



char nomFich[22];

int i;
for(i=0;i<=21;i++)
{
    sprintf(nomFich,"wal2/%d.png",i);
    p->tab[i]=IMG_Load(nomFich);
}
p->position_actuel=11;
p->time=0;
p->score=0;
p->vie=5;
}



