CC = gcc
CFLAGS = -W -Wall -ansi -std=c99 -g
LIBS =
LDFLAGS = `sdl2-config --cflags --libs`
INCLUDES =
EXEC = jeu
SRC = jeu.c
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
