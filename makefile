CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJS = main.o interface.o songlist.o song.o utils.o

main:     $(OBJS)

main.o: interface.h songlist.h song.h utils.h

interface.o: songlist.h song.h utils.h

songlist.o: song.h utils.h

song.o: utils.h

clean:
	rm main *.o
