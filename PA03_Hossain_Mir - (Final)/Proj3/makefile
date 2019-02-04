OBJS	= PQueue.o proj3.o
SOURCE	= PQueue.cpp proj3.cpp
HEADER	= PQueue.h
OUT	= proj3
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

PQueue.o: PQueue.cpp
	$(CC) $(FLAGS) PQueue.cpp

proj3.o: proj3.cpp
	$(CC) $(FLAGS) proj3.cpp


clean:
	rm -f $(OBJS) $(OUT)
