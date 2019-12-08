CC = gcc
CFLAGS = -W -Wall -ansi -std=c99 -g `sdl2-config --cflags`
LIBS =
LDFLAGS = `sdl2-config --libs`
INCLUDES =
EXEC = jeu
SRC = jeu.c fenetreDuJeu.c finDeJeu.c gestionDesTouches.c map.c personnage.c lecture_map.c menu.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)
jeu: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 
clean:
	rm -rf *.o *~
mrproper: clean
	rm -rf $(EXEC)
