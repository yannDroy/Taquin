GC = gcc
OPTIONS = -Wall -g -lSDL -lSDL_image -lSDL_ttf

Taquin : display.o image.o menu.o file_rw.o main.o
	$(GC) -o Taquin display.o image.o menu.o file_rw.o main.o $(OPTIONS)

main.o : main.c const.h
	$(GC) $(OPTIONS) -c main.c

display.o : display.c display.h
	$(GC) $(OPTIONS) -c display.c

image.o : image.c image.h
	$(GC) $(OPTIONS) -c image.c

menu.o : menu.c menu.h
	$(GC) $(OPTIONS) -c menu.c

file_rw.o : file_rw.c file_rw.h
	$(GC) $(OPTIONS) -c file_rw.c

clean :
	rm -f *.o Taquin
