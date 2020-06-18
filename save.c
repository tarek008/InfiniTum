#include "joeur.h"

void SaveGame(char* nomFich,PERSO_PRINCIPALE p,BACKGROUND b, Vie vie , Score score )
{
FILE* f=NULL;
f=fopen(nomFich,"w");
fprintf(f,"%d %hd %hd %d %d\n",vie.valVie,p.sens_mouvement,p.position.x,p.position.y,score.scoreActuel);
fprintf(f,"%d %d\n",b.position.x,b.position.y);
fclose(f);
}
/*-----------------------------------------------------------------------------------------*/
void LoadGame(char* nomFich,PERSO_PRINCIPALE *p,BACKGROUND* b, Vie* vie, Score* score)
{
FILE* f=NULL;
f=fopen(nomFich,"r");
fscanf(f,"%d %d %hd %hd %d\n",&vie->valVie,&p->sens_mouvement,&p->position.x,&p->position.y,&score->scoreActuel);
fscanf(f,"%hd %hd\n",&b->position.x,&b->position.y);
fclose(f);
}
