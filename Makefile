prog:main.o joueur.o background.o
	gcc main.o background.o joueur.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -g
joueur.o:joueur.c
	gcc -c joueur.c -g

background.o:background.c
	gcc -c background.c -g
