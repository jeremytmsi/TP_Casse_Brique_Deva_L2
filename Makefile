CC=gcc
EXEC=Casse_Brique
LDFLAGS=-I include/SDL2 -L lib/SDL2

all= $(EXEC)

Casse_Brique: obj/main.o obj/create_app.o obj/dessin.o obj/render.o obj/struct.o
	$(CC) $(LDFLAGS) -o Casse_brique obj/main.o obj/create_app.o obj/dessin.o obj/render.o obj/struct.o -lmingw32 -lSDL2main -lSDL2

obj/main.o: src/main.c obj/
	$(CC) $(LDFLAGS) -c src/main.c -o obj/main.o

obj/create_app.o: src/create_app.c obj/
	$(CC) $(LDFLAGS) -c src/create_app.c -o obj/create_app.o

obj/dessin.o: src/dessin.c obj/
	$(CC) $(LDFLAGS) -c src/dessin.c -o obj/dessin.o

obj/render.o: src/render.c obj/
	$(CC) $(LDFLAGS) -c src/render.c -o obj/render.o

obj/struct.o: src/struct.c obj/
	$(CC) $(LDFLAGS) -c src/struct.c -o obj/struct.o

obj/ :
	mkdir obj