CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJS = main.o interface.o songlist.o song.o funcs.o

main:     $(OBJS)

main.o: interface.h songlist.h song.h funcs.h

interface.o: songlist.h song.h funcs.h

songlist.o: song.h funcs.h

song.o: funcs.h

clean:
	rm main *.o 
