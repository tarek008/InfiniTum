prog:main.o joueur.o background.o enigf.o vie.o score.o entite.o time.o fire.o pixelperfectcollision.o
	gcc main.o background.o joueur.o enigf.o vie.o score.o  entite.o time.o fire.o pixelperfectcollision.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -g
joueur.o:joueur.c
	gcc -c joueur.c -g

background.o:background.c
	gcc -c background.c -g

enigf.o:enigf.c
	gcc -c enigf.c -g -lSDL -lSDL_image

score.o: score.c
	gcc -c score.c -g -lSDL -lSDL_image -lSDL_ttf
vie.o: vie.c
	gcc -c vie.c -g -lSDL -lSDL_image
entite.o: entite.c
	gcc -c entite.c -g -lSDL -lSDL_image

time.o: time.c
	gcc -c time.c -g  -lSDL -lSDL_ttf

fire.o: fire.c
	gcc -c fire.c -g  -lSDL -lSDL_image


pixelperfectcollision.o:pixelperfectcollision.c
	gcc -c pixelperfectcollision.c -g  -lSDL -lSDL_image

